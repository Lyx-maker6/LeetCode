#include <vector>
#include <cmath>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;

    // 快速幂求逆元（模运算下的除法）
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
        int n = nums.size();
        int B = sqrt(n); // 分治界限
        
        // 按照你的习惯，用一个变量存储输入
        vector<vector<int>>& bravexuneth = queries;

        // 1. 先把所有查询按步长 k 分类
        // small_k[k] 存储所有步长为 k 的查询任务
        vector<vector<pair<int, int>>> small_k(B + 1);
        
        for (auto& q : bravexuneth) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (v == 1) continue;

            if (k > B) {
                // 大步长：直接暴力更新 nums
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                // 小步长：先存起来
                small_k[k].push_back({l, r});
                // 这里有个小技巧：把 v 也存进去，我们存 {l, r, v}
                // 为了简单，我们直接存个结构或者多开个 vector
            }
        }
        
        // 我们重新组织一下小步长的存储，方便处理
        struct QueryInfo { int l, r, v; };
        vector<vector<QueryInfo>> tasks(B + 1);
        for (auto& q : bravexuneth) {
            if (q[2] <= B && q[3] != 1) {
                tasks[q[2]].push_back({q[0], q[1], q[3]});
            }
        }

        // 2. 逐个处理小步长 k
        for (int k = 1; k <= B; ++k) {
            if (tasks[k].empty()) continue;

            // 针对当前步长 k 的差分数组
            vector<long long> diff(n + k + 1, 1);
            for (auto& t : tasks[k]) {
                diff[t.l] = (diff[t.l] * t.v) % MOD;
                // 计算该序列中 r 之后的第一个位置
                int next_idx = t.l + ((t.r - t.l) / k + 1) * k;
                if (next_idx < n) {
                    diff[next_idx] = (diff[next_idx] * modInverse(t.v)) % MOD;
                }
            }

            // 还原：在步长为 k 的序列上累乘
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                if (diff[i] != 1) {
                    nums[i] = (1LL * nums[i] * diff[i]) % MOD;
                }
            }
        }

        // 3. 最终异或结果
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};