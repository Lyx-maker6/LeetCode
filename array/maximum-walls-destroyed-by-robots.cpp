#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> r(n);
        for (int i = 0; i < n; i++) r[i] = {robots[i], distance[i]};
        
        // 1. 机器人位置排序，确定物理邻居
        sort(r.begin(), r.end());

        // 2. 墙壁去重并排序
        sort(walls.begin(), walls.end());
        walls.erase(unique(walls.begin(), walls.end()), walls.end());

        // 3. 计算每个机器人真实的“火力区间”
        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; i++) {
            int pos = r[i].first;
            int d = r[i].second;

            // 向左射击：不能击中左邻居，所以左边界 L 最小为 r[i-1].first + 1
            int L = (i == 0) ? pos - d : max(pos - d, r[i - 1].first + 1);
            if (L <= pos) intervals.push_back({L, pos});

            // 向右射击：不能击中右邻居，所以右边界 R 最大为 r[i+1].first - 1
            int R = (i == n - 1) ? pos + d : min(pos + d, r[i + 1].first - 1);
            if (R >= pos) intervals.push_back({pos, R});
        }

        // 4. 合并所有重叠的火力区间
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> merged;
        if (!intervals.empty()) {
            merged.push_back(intervals[0]);
            for (int i = 1; i < (int)intervals.size(); i++) {
                if (intervals[i].first <= merged.back().second) {
                    merged.back().second = max(merged.back().second, intervals[i].second);
                } else {
                    merged.push_back(intervals[i]);
                }
            }
        }

        // 5. 统计被覆盖的墙壁数量（双指针高效扫描）
        int ans = 0;
        int curr_int = 0;
        for (int w : walls) {
            while (curr_int < (int)merged.size() && merged[curr_int].second < w) {
                curr_int++;
            }
            if (curr_int < (int)merged.size() && w >= merged[curr_int].first) {
                ans++;
            }
        }

        return ans;
    }
};