#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public://三维动态规划
    long long maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // 使用 long long 防止加法溢出，初始化为极小值
        // dp[i][j][k] 表示到达 (i, j) 使用了 k 次免疫
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, -1e18)));

        // 初始化起点 (0, 0)
        // 情况1: 不用免疫
        dp[0][0][0] = coins[0][0];
        // 情况2: 如果起点就是负数，可以用一次免疫
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k < 3; ++k) {
                    long long prev_max = -1e18;
                    if (i > 0) prev_max = max(prev_max, dp[i - 1][j][k]);
                    if (j > 0) prev_max = max(prev_max, dp[i][j - 1][k]);

                    if (prev_max != -1e18) {
                        // 1. 不使用免疫，直接加上当前格子的值
                        dp[i][j][k] = max(dp[i][j][k], prev_max + coins[i][j]);

                        // 2. 如果当前是负数且还有免疫次数可用
                        if (coins[i][j] < 0 && k + 1 < 3) {
                            long long prev_k_minus_1 = -1e18;
                            if (i > 0) prev_k_minus_1 = max(prev_k_minus_1, dp[i - 1][j][k]);
                            if (j > 0) prev_k_minus_1 = max(prev_k_minus_1, dp[i][j - 1][k]);
                            
                            // 消耗一次免疫，k 变成 k+1，值不减少
                            dp[i][j][k + 1] = max(dp[i][j][k + 1], prev_k_minus_1);
                        }
                    }
                }
            }
        }

        // 最终结果是到达右下角，使用 0, 1, 或 2 次免疫中的最大值
        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};