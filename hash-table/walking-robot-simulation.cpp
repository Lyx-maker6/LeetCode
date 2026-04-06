class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //方向数组：北(0), 东(1), 南(2), 西(3)
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir = 0;
        int x = 0,y = 0;
        int maxDistSq = 0;

        unordered_set<string> obsSet;
        for (const auto& obs : obstacles) {
            obsSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        for (int cmd : commands) {

            if (cmd == -2) {
                // 向左转：索引减 1，加 4 取模防止负数
                dir = (dir + 3) % 4;
            } else if (cmd == -1) {
                // 向右转：索引加 1
                dir = (dir + 1) % 4;
            } else {
                // 向前走 cmd 步
                for (int k = 0; k < cmd; k++) {
                    int nextX = x + dx[dir];
                    int nextY = y + dy[dir];

                    // 检查下一步是否是障碍物
                    if (obsSet.find(to_string(nextX) + "," + to_string(nextY)) == obsSet.end()) {
                        x = nextX;
                        y = nextY;
                        maxDistSq = max(maxDistSq, x * x + y * y);
                    } else {
                        // 撞到障碍物，停留在原位，跳出本次步数循环
                      break;
                    }
                }
            }
        }
        return maxDistSq;
    }
};