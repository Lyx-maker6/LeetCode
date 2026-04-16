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

        // 尝试检查右侧元素
        if (it != indices.end()) {
            // 如果 lower_bound 正好找到 q 自己，那我们就尝试右边那个元素，或者如果右边没有，尝试左边那个元素
            int next_idx = (*it == q) ? (next(it) == indices.end() ? -1 : *next(it)) : *it;
            if (next_idx != -1) {
                int d = abs(next_idx - q);
                min_v = min(min_v, min(d, m - d));
            }
        }
        
        // 尝试检查左侧元素
        if (it != indices.begin()) {
            int left_idx = (prev(it) == indices.end()) ? -1 : *prev(it); // 在 lower_bound it 上做 prev 是安全的
             if (left_idx != -1 && left_idx != q) { // 这里多加一个逻辑防御
                int d = abs(left_idx - q);
                min_v = min(min_v, min(d, m - d));
            }
        }
        
        // 关键补充：检查有序列表的首尾连接 (针对 q=0 或 q=m-1 这样的情况)
        if (indices.front() != q) {
             int d = abs(indices.front() - q);
             min_v = min(min_v, min(d, m - d));
        }
        if (indices.back() != q) {
             int d = abs(indices.back() - q);
             min_v = min(min_v, min(d, m - d));
        }

        ans.push_back(min_v == INT_MAX ? -1 : min_v);
    }
    return ans;
    }
};