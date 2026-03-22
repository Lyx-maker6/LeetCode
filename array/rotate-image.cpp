class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();

        for(int i = 0; i < row; i++)
        {
            for(int j = i+1; j < row; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // for(int i = 0; i < row; i++)
        // {
        //     for(int j = 0; j < row / 2; j++)
        //     {
        //         swap(matrix[i][j], matrix[i][row - 1 - j]);
        //     }
        // }
        for (int k = 0 ; k < row ; k++){
            reverse(matrix[k].begin(), matrix[k].end());
        }

        
    }
};