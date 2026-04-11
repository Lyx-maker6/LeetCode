#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;
        
        // 存储每个数字出现的所有下标
        unordered_map<int, vector<int>> pos_map;
        for (int i = 0; i < n; i++) {
            pos_map[nums[i]].push_back(i);
        }

        int min_dist = -1;

        // 遍历所有数字的下标列表
        for (auto& entry : pos_map) {
            const vector<int>& p = entry.second;
            
            // 如果某数字出现次数小于3，无法构成 good tuple
            if (p.size() < 3) continue;

            // 只需要检查相邻的三元组，例如下标 p[0], p[1], p[2]
            // p[i+2] 是 k，p[i] 是 i
            for (int i = 0; i + 2 < p.size(); i++) {
                int current_dist = 2 * (p[i + 2] - p[i]);
                
                if (min_dist == -1 || current_dist < min_dist) {
                    min_dist = current_dist;
                }
            }
        }

        return min_dist;
    }
};