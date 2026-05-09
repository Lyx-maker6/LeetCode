class Solution {
public:
    // 核心修改：将函数名改为 rotateGrid 以匹配接口
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2; // 由于 m, n 为偶数，层数刚好是较短边的一半

        for (int i = 0; i < layers; i++) {
            // 1. 定义当前层的边界
            int r1 = i, c1 = i;
            int r2 = m - 1 - i, c2 = n - 1 - i;

            // 2. 提取当前层元素（逆时针顺序：上 -> 右 -> 下 -> 左）
            vector<int> elements;
            for (int j = c1; j < c2; j++) elements.push_back(grid[r1][j]); // 上
            for (int j = r1; j < r2; j++) elements.push_back(grid[j][c2]); // 右
            for (int j = c2; j > c1; j--) elements.push_back(grid[r2][j]); // 下
            for (int j = r2; j > r1; j--) elements.push_back(grid[j][c1]); // 左

            // 3. 处理旋转逻辑
            int len = elements.size();
            int realK = k % len; // 利用取模优化超大旋转次数 k
            if (realK == 0) continue; // 如果不需要旋转，直接处理下一层

            // 4. 将旋转后的元素重新填回矩阵
            // 逆时针旋转 k 次，意味着数组中的元素向“前”移动 realK 位
            int idx = realK; 
            for (int j = c1; j < c2; j++) grid[r1][j] = elements[idx++ % len];
            for (int j = r1; j < r2; j++) grid[j][c2] = elements[idx++ % len];
            for (int j = c2; j > c1; j--) grid[r2][j] = elements[idx++ % len];
            for (int j = r2; j > r1; j--) grid[j][c1] = elements[idx++ % len];
        }

        return grid;
    }
};