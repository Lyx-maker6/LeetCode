class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int r = mat.size();
        int c = mat[0].size();
        
        vector<vector<int>> origin = mat; 
        vector<vector<int>> re_mat = mat;

        int cnt = 0;
        while(cnt < k)
        {
            //转偶数行
            for(int i = 0; i < r; i+=2)
            { 
                int tp = mat[i].front();
                for(int j = 0;j < c-1;j++)
                {
                    re_mat[i][j]=mat[i][j+1];
                }
                re_mat[i][c-1] = tp;
            }
            //转奇数行
            for(int i = 1; i < r; i+=2)
            {
                int tp = mat[i].back(); 
                 for (int j = c - 1; j > 0; --j) 
                {
                      re_mat[i][j] = mat[i][j - 1];
                }
                re_mat[i][0] = tp;
            }
            mat = re_mat;
            cnt++;
            if(mat==origin)
                return true; 
        }
        
        
        return false;
    }
};