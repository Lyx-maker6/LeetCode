class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> ans(r, vector<int>(c));

        int res = 1;

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                res *= grid[i][j];
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                ans[i][j] = ( res / grid[i][j] ) %12345;
            }
        }
        return ans;
            
    }
};