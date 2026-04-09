class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        long long MOD = 1e9+7;
        for(int i = 0; i < n;i++)
        {  
            int op_num = queries[i][3];
            for(int k = queries[i][0];k <= queries[i][1];k += queries[i][2])
            {
                long long temp = (long long)nums[k] * op_num;
                nums[k] = temp % MOD;
            }
        
        }

        int ans = 0;
        for(int i = 0;i < nums.size();i++)
        {
            ans ^= nums[i];
        }

        return ans;
        
    }
};