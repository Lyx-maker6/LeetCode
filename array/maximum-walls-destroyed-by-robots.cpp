#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        // 1. 存储机器人位置和距离，并按位置排序
        vector<pair<int, int>> sorted_robots;
        for (int i = 0; i < n; ++i) {
            sorted_robots.push_back({robots[i], distance[i]});
        }
        sort(sorted_robots.begin(), sorted_robots.end());

        // 2. 计算每个机器人的有效区间 [left, right]
        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; ++i) {
            int pos = sorted_robots[i].first;
            int dist = sorted_robots[i].second;

            // 左射程边界：被左边机器人挡住或到达最大距离
            int left_limit = (i == 0) ? pos - dist : max(pos - dist, sorted_robots[i-1].first);
            // 右射程边界：被右边机器人挡住或到达最大距离
            int right_limit = (i == n - 1) ? pos + dist : min(pos + dist, sorted_robots[i+1].first);

            intervals.push_back({left_limit, right_limit});
        }

        // 3. 对区间进行排序，方便后续查找
        sort(intervals.begin(), intervals.end());

        // 4. 统计被摧毁的墙（去重处理）
        set<int> unique_walls(walls.begin(), walls.end());
        int count = 0;

        for (int w : unique_walls) {
            // 使用二分查找看当前墙是否在某个区间内
            // 查找第一个可能包含 w 的区间（起点 <= w）
            auto it = lower_bound(intervals.begin(), intervals.end(), make_pair(w, (int)2e9));
            
            if (it != intervals.begin()) {
                --it;
                if (w >= it->first && w <= it->second) {
                    count++;
                }
            }
        }

        return count;
    }
};//不会