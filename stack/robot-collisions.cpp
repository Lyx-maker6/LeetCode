#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

struct Robot {
    int id;       // 原始索引
    int pos;      // 位置
    int health;   // 健康值
    char dir;     // 方向
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);
        for (int i = 0; i < n; i++) {
            robots[i] = {i, positions[i], healths[i], directions[i]};
        }

        // 1. 按物理位置从小到大排序
        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.pos < b.pos;
        });

        vector<Robot> st; // 用 vector 模拟栈，方便最后操作
        for (int i = 0; i < n; i++) {
            // 如果向右走，直接入栈（它只会撞到它右边向左走的机器人）
            if (robots[i].dir == 'R') {
                st.push_back(robots[i]);
                continue;
            }

            // 如果向左走，尝试与栈中向右走的机器人碰撞
            while (!st.empty() && st.back().dir == 'R' && robots[i].health > 0) {
                if (st.back().health < robots[i].health) {
                    // 栈顶消失，当前机器人减血
                    st.pop_back();
                    robots[i].health -= 1;
                } else if (st.back().health > robots[i].health) {
                    // 当前机器人消失，栈顶减血
                    st.back().health -= 1;
                    robots[i].health = 0;
                } else {
                    // 同归于尽
                    st.pop_back();
                    robots[i].health = 0;
                }
            }

            // 如果碰撞完还活着（或者没遇到向右的），入栈
            if (robots[i].health > 0) {
                st.push_back(robots[i]);
            }
        }

        // 2. 恢复原始顺序
        sort(st.begin(), st.end(), [](const Robot& a, const Robot& b) {
            return a.id < b.id;
        });

        vector<int> res;
        for (auto& r : st) res.push_back(r.health);
        return res;
    }
};