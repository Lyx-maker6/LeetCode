#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> r(n);
        for (int i = 0; i < n; i++) {
            r[i] = {robots[i], distance[i]};
        }
        // 1. 机器人必须排序确定邻居
        sort(r.begin(), r.end());

        // 2. 墙壁去重
        sort(walls.begin(), walls.end());
        walls.erase(unique(walls.begin(), walls.end()), walls.end());

        // 3. 核心：提取所有独立的、不越过邻居的火力区间
        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; i++) {
            int pos = r[i].first;
            int d = r[i].second;

            // 左射程：[max(远端, 左邻居), pos]
            int left_b = (i == 0) ? pos - d : max(pos - d, r[i-1].first);
            intervals.push_back({left_b, pos});

            // 右射程：[pos, min(远端, 右邻居)]
            int right_b = (i == n - 1) ? pos + d : min(pos + d, r[i+1].first);
            intervals.push_back({pos, right_b});
        }

        // 4. 区间排序并合并
        // 虽然机器人相互阻挡，但不同机器人的火力区间可能重叠（比如 A 往右打到 B，B 往左打到 A）
        // 合并重叠区间是为了用双指针高效统计墙壁
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

        // 5. 统计在合并区间内的墙壁数量
        int ans = 0;
        int interval_idx = 0;
        for (int w : walls) {
            // 找到第一个可能覆盖这堵墙的区间
            while (interval_idx < merged.size() && merged[interval_idx].second < w) {
                interval_idx++;
            }
            // 检查这堵墙是否在当前区间内
            if (interval_idx < merged.size() && w >= merged[interval_idx].first) {
                ans++;
            }
        }

        return ans;
    }
};