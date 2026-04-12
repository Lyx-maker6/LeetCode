class Solution {
    int dist(int a, int b) {
        if (a == 26) return 0; // 初始自由位置，不计距离
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

public:
    int minimumDistance(string word) {
        int n = word.size();
        // dp[last_other_pos] 表示另一个手指在 last_other_pos 时的最小距离
        // 26 代表初始自由位置
        vector<int> dp(27, 0); 
        
        for (int i = 0; i < n - 1; ++i) {
            int curr = word[i] - 'A';
            int next = word[i+1] - 'A';
            vector<int> next_dp(27, 1e9);
            
            for (int other = 0; other < 27; ++other) {
                if (dp[other] >= 1e9) continue;
                
                // 选择1：用留在 curr 的手指移动到 next
                next_dp[other] = min(next_dp[other], dp[other] + dist(curr, next));
                
                // 选择2：用留在 other 的手指移动到 next
                next_dp[curr] = min(next_dp[curr], dp[other] + dist(other, next));
            }
            dp = next_dp;
        }
        
        int ans = 1e9;
        for (int d : dp) ans = min(ans, d);
        return ans;
    }
};