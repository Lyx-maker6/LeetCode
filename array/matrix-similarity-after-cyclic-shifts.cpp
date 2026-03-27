class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int r = mat.size();
        int c = mat[0].size();
        // 优化点：k 如果很大，模拟会超时。因为每移动 c 次就会回到原点。
        k %= c;
        // 如果 k 为 0（包括原值就是 0，或者 k 是 c 的倍数），直接返回 true
        if (k == 0) return true;

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
        }
        return mat == origin;
    }
};