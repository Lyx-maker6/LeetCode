#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;

    // 费马小定理求逆元：v^(MOD-2) % MOD
    long long modInverse(long long n) {
        long long res = 1, exp = MOD - 2;
        n %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * n) % MOD;
            n = (n * n) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size();
        int B = sqrt(m); // 根号分治阈值

        // 存储小步长的查询：k_queries[step][ {l, r, v} ]
        map<int, vector<vector<int>>> k_queries;
        
        // 1. 处理大步长或收集小步长
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (v == 1) continue; // 乘1无意义，跳过

            if (k > B) {
                // 大步长直接暴力：单次执行次数 < sqrt(m)
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                // 小步长按 k 分组存储
                k_queries[k].push_back({l, r, v});
            }
        }

        // 2. 逐个步长 k 处理小步长差分
        // 这样可以复用 diff 数组，避免 O(m*sqrt(m)) 的空间开销
        for (auto& entry : k_queries) {
            int k = entry.first;
            vector<long long> diff(m + k + 1, 1);
            
            for (auto& q : entry.second) {
                int l = q[0], r = q[1], v = q[2];
                
                // 乘法差分：起点乘 v
                diff[l] = (diff[l] * v) % MOD;
                
                // 找到该序列中 r 之后的第一个跳跃点
                int count = (r - l) / k;
                int next_pos = l + (count + 1) * k;
                
                // 终点后点乘逆元（相当于除以 v）
                if (next_pos < m) {
                    diff[next_pos] = (diff[next_pos] * modInverse(v)) % MOD;
                }
            }

            // 还原当前步长 k 的所有影响
            for (int i = 0; i < m; ++i) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                if (diff[i] != 1) {
                    nums[i] = (1LL * nums[i] * diff[i]) % MOD;
                }
            }
        }

        // 3. 计算最终异或和
        int ans = 0;
        for (int val : nums) {
            ans ^= val;
        }
        return ans;
    }
};