class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<long long> row(c);
        vector<long long> col(r);

        // 1. 计算矩阵总和
        long long total = 0;
        for (auto& row : grid) {
            for (int num : row) {
                total += num;
            }
        }
         // 总和为奇数，不可能分割
        if (total % 2 != 0) return false;
        long long target = total / 2;

        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++)
                col[i] += grid[i][j];
         
        for(int i = 0;i < c;i++)
            for(int j = 0;j < r;j++)
                row[i] += grid[j][i];
        
        long long tp = 0;
        for(int i = 0;i < r;i++)
        {
            tp += col[i];

            if(tp == target)
                return 1;
        }

        tp = 0;//重置tp
        for(int i = 0;i < c;i++)
        {
            tp += row[i];

            if(tp == target)
                return 1;
        }
        return 0;
   
    }
};