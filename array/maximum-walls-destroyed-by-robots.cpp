#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solve(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
    int n = robots.size();
    // 1. 记录机器人原始索引并排序，因为 distance 与 robots 一一对应
    vector<pair<int, int>> sorted_robots;
    for (int i = 0; i < n; ++i) {
        sorted_robots.push_back({robots[i], distance[i]});
    }
    sort(sorted_robots.begin(), sorted_robots.end());

    // 2. 统计每个机器人覆盖的区间
    // 区间用 pair<int, int> 表示 [left, right]
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; ++i) {
        int pos = sorted_robots[i].first;
        int dist = sorted_robots[i].second;

        // 左侧射程
        int left_limit = (i == 0) ? pos - dist : max(pos - dist, sorted_robots[i-1].first);
        intervals.push_back({left_limit, pos});

        // 右侧射程
        int right_limit = (i == n - 1) ? pos + dist : min(pos + dist, sorted_robots[i+1].first);
        intervals.push_back({pos, right_limit});
    }

    // 3. 对区间进行合并（可选优化）并对墙壁进行计数
    sort(intervals.begin(), intervals.end());
    
    // 使用 set 对墙壁去重（如果有重复位置的墙）
    set<int> unique_walls(walls.begin(), walls.end());
    int destroyed_count = 0;

    // 遍历每一堵墙，看它是否在某个区间内
    for (int wall_pos : unique_walls) {
        // 在 intervals 中查找可能覆盖该墙的区间（二分查找）
        auto it = lower_bound(intervals.begin(), intervals.end(), make_pair(wall_pos, (int)2e9));
        // 检查前一个区间是否包含此墙
        if (it != intervals.begin()) {
            it--;
            if (wall_pos >= it->first && wall_pos <= it->second) {
                destroyed_count++;
            }
        }
    }

    return destroyed_count;
}