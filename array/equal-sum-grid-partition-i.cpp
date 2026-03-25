class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> row(c);
        vector<int> col(r);

        // 1. 计算矩阵总和
        int total = 0;
        for (auto& row : grid) {
            for (int num : row) {
                total += num;
            }
        }
         // 总和为奇数，不可能分割
        if (total % 2 != 0) return false;
        int target = total / 2;

        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++)
                col[i] += grid[i][j];
         
        for(int i = 0;i < c;i++)
            for(int j = 0;j < r;j++)
                row[i] += grid[j][i];
        
        int flag = 0;
        for(int i = 0;i < r;i++)
        {
            int tp = 0;
            tp += col[i];

            if(tp == target)
                return 1;
            else
                flag=0;
        }
        for(int i = 0;i < c;i++)
        {
            int tp = 0;
            tp += row[i];

            if(tp == target)
                return 1;
            else
                flag=0;
        }

        if(flag == 0)
            return 0;
        
        return 1;
    }
};