class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 1. 转置矩阵：沿着主对角线翻转
        for (int i = 0; i < n; i++) {
            // 注意 j 从 i 开始，只处理对角线的一侧，否则换过去又换回来了
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. 左右镜像：反转每一行
        for (int i = 0; i < n; i++) {
            // 使用 reverse 直接反转整行
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};