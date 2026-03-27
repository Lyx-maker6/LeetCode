class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> re_mat(r);

        int cnt = 0;
        while(cnt < c)
        {
            if(mat!=re_mat)
                return true; 
            //转偶数行
            for(int i = 0; i < r; i+=2)
            {
                int tp = mat[i].front();
                for(int j = 0;i < c;j++)
                {
                    re_mat[i][j]=mat[i][j+1];
                }
                re_mat[i][c-1] = tp;
            }
            //转奇数行
            for(int i = 1; i < r; i+=2)
            {
                int tp = mat[i].front();
                for(int j = 0;i < c;j++)
                {
                    re_mat[i][j]=mat[i][j+1];
                }
                re_mat[i][c-1] = tp;
            }
        }
        return false;
    }
};