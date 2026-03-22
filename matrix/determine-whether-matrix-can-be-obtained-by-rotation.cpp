class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int row = mat.size();
        int cnt = 0;//最多转四次
        while(cnt < 4){
            if(mat==target)
                return true;
            for(int i = 0; i < row; i++)
            {
                for(int j = i + 1; j < row; j++)
                {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for(int i = 0; i < row; i++)
            {
                for(int j = 0;j < row / 2; j++)
                {
                    swap(mat[i][j], mat[i][row-j-1]);
                } 
            }
            cnt++;
        }
        return false;
    }
};