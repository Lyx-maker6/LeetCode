class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int max_val = nums[0];
        // int min_val = nums[0];
        // int ans = nums[0];

        // for(int i = 1;i < nums.size(); i++)
        // {
        //     int num = nums[i];

        //     if(num < 0)
        //         swap(max_val, min_val);
            
        //     max_val = max(num, num * max_val);
        //     min_val = min(num, num * min_val);
        //     ans = max(max_val, ans);
        // }
        // return ans;

        //下面尝试动态规划写发
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> max_dp(n);
        vector<int> min_dp(n);
        max_dp[0] = min_dp[0] = nums[0];
        int ans = nums[0]; // 全局最大值

        for(int i = 1; i < n; i++)
        {
            int cur = nums[i];
            if(cur >= 0)
            {
                max_dp[i] = max(max_dp[i-1] * cur, cur);
                min_dp[i] = min(min_dp[i-1] * cur, cur);
            }
            else
            {
                max_dp[i] = max(min_dp[i-1] * cur, cur);
                min_dp[i] = min(max_dp[i-1] * cur, cur);
            }
            ans = max(ans, max_dp[i]);
        }
        return ans;

    }
};