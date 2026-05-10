class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // dp[i] 存储到达下标 i 的最大跳跃次数，初始化为 -1 表示不可达
        vector<int> dp(n, -1);
        
        // 初始点
        dp[0] = 0;

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                // 只有当 i 点本身可达时，才能作为跳跃的起点
                if (dp[i] != -1) {
                    // 检查跳跃条件
                    if (abs((long long)nums[j] - nums[i]) <= (long long)target) {
                        dp[j] = max(dp[j], dp[i] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};