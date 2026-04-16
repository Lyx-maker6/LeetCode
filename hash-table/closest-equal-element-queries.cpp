class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // int n = queries.size();
        // vector<int> ans;

        // int m = nums.size();
       
        // for(auto q : queries)
        // {
        //     int min_v = INT_MAX;
        //     int d = 0;

        //     for(int i = 0;i < nums.size();i++)
        //     {
        //         // 必须满足 nums[i] == nums[q] 且 i != q
        //         if(i != q && nums[i] == nums[q])
        //         {
        //             d = abs(i - q);
        //             int re_d = m - d;
        //             min_v = min(min_v,min(d,re_d));
        //         }
        //     }
        //     if(min_v == INT_MAX) ans.push_back(-1);
        //     else ans.push_back(min_v);
        // }
        // return ans;


        int m = nums.size();
        unordered_map<int, vector<int>> pos_map;
        for (int i = 0; i < m; i++) pos_map[nums[i]].push_back(i);

        vector<int> ans;
        for (int q : queries) {
        int targetVal = nums[q];
        if (pos_map[targetVal].size() == 1) { // 如果该数值只有一个索引，则必无解
            ans.push_back(-1); continue;
        }

        const vector<int>& indices = pos_map[targetVal];
        auto it = lower_bound(indices.begin(), indices.end(), q);
        int min_v = INT_MAX;

        // 尝试检查右侧
    }
};