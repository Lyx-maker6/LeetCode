class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        // 1. 关联位置和距离并排序
        vector<pair<int, int>> r(n);
        for(int i = 0; i < n; i++) r[i] = {robots[i], distance[i]};
        sort(r.begin(), r.end());

        // 2. 收集所有可能的“摧毁区间”
        // 注意：左射程和右射程要分开，且不能包含机器人自身位置之外的逻辑
        vector<pair<int, int>> intervals;
        for(int i = 0; i < n; i++) {
            int pos = r[i].first;
            int d = r[i].second;
            
            // 向左打：最远到 pos-d，但不能过左边的机器人
            int left_limit = (i == 0) ? pos - d : max(pos - d, r[i-1].first);
            intervals.push_back({left_limit, pos});
            
            // 向右打：最远到 pos+d，但不能过右边的机器人
            int right_limit = (i == n-1) ? pos + d : min(pos + d, r[i+1].first);
            intervals.push_back({pos, right_limit});
        }

        // 3. 墙壁去重并排序
        sort(walls.begin(), walls.end());
        walls.erase(unique(walls.begin(), walls.end()), walls.end());

        // 4. 统计有多少墙在区间内
        // 因为区间多且碎，我们把区间按起点排序，然后合并重叠区间
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> merged;
        if(!intervals.empty()) {
            merged.push_back(intervals[0]);
            for(int i = 1; i < intervals.size(); i++) {
                if(intervals[i].first <= merged.back().second) {
                    merged.back().second = max(merged.back().second, intervals[i].second);
                } else {
                    merged.push_back(intervals[i]);
                }
            }
        }

        int ans = 0;
        int curr_interval = 0;
        for(int w : walls) {
            while(curr_interval < merged.size() && merged[curr_interval].second < w) {
                curr_interval++;
            }
            if(curr_interval < merged.size() && w >= merged[curr_interval].first) {
                ans++;
            }
        }
        return ans;
    }
};