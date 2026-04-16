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
        for (int i = 0; i < m; i++) {
            pos_map[nums[i]].push_back(i);
        }

        vector<int> ans;
        for (int q : queries) {
            const vector<int>& indices = pos_map[nums[q]];
            
            // 使用二分查找找到第一个大于或等于 q 的位置
            auto it = lower_bound(indices.begin(), indices.end(), q);
            
            int min_v = INT_MAX;
            
            // 检查 it 指向的元素 (右侧最近)
            if (it != indices.end() && *it != q) {
                int d = abs(*it - q);
                min_v = min(min_v, min(d, m - d));
            }
            // 检查 it 的前一个元素 (左侧最近)
            if (it != indices.begin()) {
                int left_val = *prev(it);
                if (left_val != q) {
                    int d = abs(left_val - q);
                    min_v = min(min_v, min(d, m - d));
                }
            }
            
            ans.push_back(min_v == INT_MAX ? -1 : min_v);
        }
        return ans;
    }
};