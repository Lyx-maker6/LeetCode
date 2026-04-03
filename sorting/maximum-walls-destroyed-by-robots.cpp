#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> r(n);
        for (int i = 0; i < n; i++) r[i] = {robots[i], distance[i]};
        sort(r.begin(), r.end());

        // 1. 收集所有火力区间，注意边界的开闭逻辑
        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; i++) {
            int pos = r[i].first;
            int d = r[i].second;

            // 向左打：最远 pos-d，但不能碰到左邻居。
            // 关键：左邻居那个点本身是打不到的，所以 L = 邻居pos + 1
            int L = (i == 0) ? pos - d : max(pos - d, r[i-1].first + 1);
            if (L <= pos) intervals.push_back({L, pos});

            // 向右打：最远 pos+d，但不能碰到右邻居。
            // 关键：右邻居那个点本身是打不到的，所以 R = 邻居pos - 1
            int R = (i == n - 1) ? pos + d : min(pos + d, r[i+1].first - 1);
            if (R >= pos) intervals.push_back({pos, R});
        }

        // 2. 墙壁去重并排序
        sort(walls.begin(), walls.end());
        walls.erase(unique(walls.begin(), walls.end()), walls.end());

        // 3. 合并区间
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> merged;
        if (!intervals.empty()) {
            merged.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); i++) {
                if (intervals[i].first <= merged.back().second) {
                    merged.back().second = max(merged.back().second, intervals[i].second);
                } else {
                    merged.push_back(intervals[i]);
                }
            }
        }

        // 4. 双指针统计
        int ans = 0;
        int idx = 0;
        for (int w : walls) {
            while (idx < merged.size() && merged[idx].second < w) {
                idx++;
            }
            if (idx < merged.size() && w >= merged[idx].first) {
                ans++;
            }
        }
        return ans;
    }
};