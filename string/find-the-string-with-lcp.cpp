#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        // 并查集查找函数
        auto find = [&](auto self, int i) -> int {
            return parent[i] == i ? i : parent[i] = self(self, parent[i]);
        };

        // 1. 根据 lcp[i][j] > 0 合并相等字符
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (lcp[i][j] > 0) {
                    int rootI = find(find, i);
                    int rootJ = find(find, j);
                    if (rootI != rootJ) parent[rootI] = rootJ;
                }
            }
        }

        // 2. 贪心构造字典序最小字符串
        string s(n, 0);
        char cur_char = 'a';
        for (int i = 0; i < n; ++i) {
            int root = find(find, i);
            if (s[root] == 0) {
                if (cur_char > 'z') return ""; // 超过26个字母，无法构造
                s[root] = cur_char++;
            }
            s[i] = s[root];
        }

        // 3. 验证构造出的字符串是否符合原 LCP 矩阵
        // 使用 DP 从后往前计算构造串的 LCP
        vector<vector<int>> actual(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == s[j]) {
                    actual[i][j] = actual[i + 1][j + 1] + 1;
                } else {
                    actual[i][j] = 0;
                }
                // 关键：与输入矩阵实时比对
                if (actual[i][j] != lcp[i][j]) return "";
            }
        }

        return s;
    }
};