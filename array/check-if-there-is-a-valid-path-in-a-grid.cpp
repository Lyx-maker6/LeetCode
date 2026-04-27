class Solution {
public:
    int m, n;
    bool visited[300][300];
    
    // 定义 6 种形状分别对应的两个出口方向 {dx, dy}
    // dx: -1上, 1下; dy: -1左, 1右
    vector<vector<pair<int, int>>> dirs = {
        {}, // 占位
        {{0, -1}, {0, 1}},  // 1: 左, 右
        {{-1, 0}, {1, 0}},  // 2: 上, 下
        {{0, -1}, {1, 0}},  // 3: 左, 下
        {{0, 1}, {1, 0}},   // 4: 右, 下
        {{0, -1}, {-1, 0}}, // 5: 左, 上
        {{0, 1}, {-1, 0}}   // 6: 右, 上
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(visited, false, sizeof(visited));
        return dfs(0, 0, grid);
    }

    bool dfs(int x, int y, vector<vector<int>>& grid) {
        if (x == m - 1 && y == n - 1) return true; // 到达终点
        visited[x][y] = true;

        int type = grid[x][y];
        for (auto& d : dirs[type]) {
            int nx = x + d.first;
            int ny = y + d.second;

            // 1. 越界检查
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;

            // 2. 双向连接检查
            // 看看邻居格子 (nx, ny) 的出口里，有没有一个能回到 (x, y)
            bool can_connect = false;
            int n_type = grid[nx][ny];
            for (auto& nd : dirs[n_type]) {
                if (nx + nd.first == x && ny + nd.second == y) {
                    can_connect = true;
                    break;
                }
            }

            if (can_connect && dfs(nx, ny, grid)) return true;
        }
        return false;
    }
};