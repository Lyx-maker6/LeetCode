class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> ans(r, vector<int>(c));
        long long pre = 1;//前缀积
        long long last = 1;//后缀积

        //从前往后算
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                ans[i][j] = pre;//pre相当于接力棒，先把接力棒传给当前这个数
                pre = (pre * grid[i][j]) % 12345;//更新值
            }
        }
        //从后往前算
        for(int i = r-1; i >= 0; i--)
        {
            for(int j = c-1; j >= 0; j--)
            {
                ans[i][j] = (ans[i][j] * last) % 12345;
                last = (last * grid[i][j]) % 12345;
            }
        }

        return ans;
            
    }
};