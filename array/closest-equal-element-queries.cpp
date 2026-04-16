class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans;

        int m = nums.size();
       
        for(auto q : queries)
        {
            int min_v = INT_MAX;
            int d = 0;

            for(int i = 0;i < nums.size();i++)
            {
                // 必须满足 nums[i] == nums[q] 且 i != q
                if(i != q && nums[i] == nums[q])
                {
                    d = abs(i - q);
                    int re_d = m - d;
                    min_v = min(min_v,min(d,re_d));
                }
            }
            if(min_v == INT_MAX) ans.push_back(-1);
            else ans.push_back(min_v);
        }
        return ans;
    }


};