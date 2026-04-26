class Solution {
public:
    int m, n;
    bool visited[500][500];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py, char target) {
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 1. 越界检查
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            // 2. 只有字符相同才能走
            if (grid[nx][ny] != target) continue;
            
            if (visited[nx][ny]) {
                // 如果这个点走过，且它不是我们的“来路”（父节点），说明找到环了！
                if (nx != px || ny != py) return true;
            } else {
                // 如果没走过，继续 DFS
                if (dfs(grid, nx, ny, x, y, target)) return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 每个没访问过的点都可能是一个环的起点
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1, grid[i][j])) return true;
                }
            }
        }
        return false;
    }
};