class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> row(c);
        vector<int> col(r);

        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++)
                col[i] += grid[i][j];
         
        for(int i = 0;i < c;i++)
            for(int j = 0;j < r;j++)
                row[i] += grid[j][i];
            
        int sum_r = 0, sum_c = 0;
        for(int i = 0;i < r;i++)
            sum_c += col[i];
        for(int i = 0;i < c;i++)
            sum_r += row[i];

        int flag = 0;
        for(int i = 0;i < r;i++)
        {
            int tp = 0;
            tp += col[i];

            if(tp == sum_c / 2)
                return 1;
            else
                flag=0;
        }
        for(int i = 0;i < c;i++)
        {
            int tp = 0;
            tp += row[i];

            if(tp == sum_r / 2)
                return 1;
            else
                flag=0;
        }

        if(flag == 0)
            return 0;
        
        return 1;
    }
};