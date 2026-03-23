class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        long long res;
        long long MOD = 1e9+7;
        //动态规划
        //step1:定义两个状态数组，维护状态
        vector<vector<long long>> max_dp(r,vector<long long>(c));
        vector<vector<long long>> min_dp(r,vector<long long>(c));
        
        //step2:状态转移方程
        //step2_1:初始两个状态元素的第一个
        max_dp[0][0] = min_dp[0][0] = grid[0][0];

        //step2_2:第一行和第一列的元素从左边来和上面来
        for(int i = 1;i < c;i++)
            max_dp[0][i] = min_dp[0][i] = max_dp[0][i-1] * grid[0][i];
        for(int i = 1;i < r;i++)
            max_dp[i][0] = min_dp[i][0] = max_dp[i-1][0] * grid[i][0];
        
        //step3: 填充剩余格子
        for(int i = 1;i < r;i++)
        {
            for(int j = 1;j < c;j++)
            {
                long long val = grid[i][j];
                
                if(val >= 0)
                {
                    // 最大 = 上/左中较大的那个 * 正数
                    max_dp[i][j] = max(max_dp[i - 1][j], max_dp[i][j - 1]) * val;
                    // 最小 = 上/左中较小的那个 * 正数
                    min_dp[i][j] = min(min_dp[i - 1][j], min_dp[i][j - 1]) * val;
                }
                else
                {
                    // 最大 = 上/左中【最小】的那个（比如-100） * 负数（比如-2） = 200
                    max_dp[i][j] = min(min_dp[i - 1][j], min_dp[i][j - 1]) * val;
                    // 最小 = 上/左中【最大】的那个（比如50） * 负数（比如-2） = -100
                    min_dp[i][j] = max(max_dp[i - 1][j], max_dp[i][j - 1]) * val;
                }
            }
        }
        res = max_dp[r-1][c-1];

        return res < 0 ? -1 : res % MOD;        
    }
};