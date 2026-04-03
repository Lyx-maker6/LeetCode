#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        // 1. 必须先排序，才能确定谁是谁的邻居
        vector<pair<int, int>> r(n);
        for (int i = 0; i < n; i++) r[i] = {robots[i], distance[i]};
        sort(r.begin(), r.end());

        // 2. 墙壁去重并排序，提高查找效率
        sort(walls.begin(), walls.end());
        walls.erase(unique(walls.begin(), walls.end()), walls.end());

        // 3. 计算每个机器人真实的左右“火力边界”
        // 我们用 vector 存所有的火力区间 [L, R]
        vector<pair<int, int>> ranges;
        for (int i = 0; i < n; i++) {
            int pos = r[i].first;
            int d = r[i].second;

            // 左火力：最远到 pos-d，但被左边机器人挡住
            int L = (i == 0) ? pos - d : max(pos - d, r[i - 1].first);
            ranges.push_back({L, pos});

            // 右火力：最远到 pos+d，但被右边机器人挡住
            int R = (i == n - 1) ? pos + d : min(pos + d, r[i + 1].first);
            ranges.push_back({pos, R});
        }

        // 4. 将所有火力区间合并（为了消除重复覆盖，提高统计速度）
        sort(ranges.begin(), ranges.end());
        vector<pair<int, int>> merged;
        if (!ranges.empty()) {
            merged.push_back(ranges[0]);
            for (int i = 1; i < ranges.size(); i++) {
                if (ranges[i].first <= merged.back().second) {
                    merged.back().second = max(merged.back().second, ranges[i].second);
                } else {
                    merged.push_back(ranges[i]);
                }
            }
        }

        // 5. 统计墙壁（双指针法：效率最高）
        int count = 0;
        int j = 0; // 区间指针
        for (int w : walls) {
            // 跳过所有在墙左边的区间
            while (j < merged.size() && merged[j].second < w) {
                j++;
            }
            // 如果当前区间覆盖了这堵墙
            if (j < merged.size() && w >= merged[j].first) {
                count++;
            }
        }

        return count;
    }
};