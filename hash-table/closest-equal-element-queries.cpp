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
        // 预处理：记录每个数字出现的所有下标
        unordered_map<int, vector<int>> pos_map;
        for (int i = 0; i < m; i++) {
            pos_map[nums[i]].push_back(i);
        }

        vector<int> ans;
        for (int q : queries) {
            int targetVal = nums[q];
            const vector<int>& indices = pos_map[targetVal];
            
            int min_v = INT_MAX;
            // 只需要遍历该数字出现的下标列表，而不是整个数组
            for (int idx : indices) {
                if (idx != q) {
                    int d = abs(idx - q);
                    int re_d = m - d;
                    min_v = min(min_v, min(d, re_d));
                }
            }
            
            ans.push_back(min_v == INT_MAX ? -1 : min_v);
        }
        return ans;
    }
};