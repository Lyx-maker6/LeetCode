#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // 1. 排序以便按区间分配
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();
        
        // 2. 初始化 DP 表，使用一个足够大的数代表无穷大
        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));

        // 基础情况：0 个机器人无论有多少工厂，距离都是 0
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 0;
        }

        // 3. 填充 DP 表
        for (int j = 1; j <= m; ++j) {
            int pos = factory[j - 1][0];
            int limit = factory[j - 1][1];
            
            for (int i = 0; i <= n; ++i) {
                // 情况 1: 不用第 j 个工厂
                dp[i][j] = dp[i][j - 1];
                
                // 情况 2: 用第 j 个工厂修理 k 个机器人
                long long current_dist = 0;
                for (int k = 1; k <= min(i, limit); ++k) {
                    current_dist += abs(robot[i - k] - pos);
                    if (dp[i - k][j - 1] != INF) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + current_dist);
                    }
                }
            }
        }

        return dp[n][m];
    }////////////////////////////////////////////////////////////////////不会
};