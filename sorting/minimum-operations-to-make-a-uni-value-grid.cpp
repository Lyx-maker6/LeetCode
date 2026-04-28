class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size();
        int n = grid[0].size();
        
        // 1. 展平网格并检查余数一致性
        int target_mod = grid[0][0] % x;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != target_mod) {
                    return -1; // 余数不同，永远不可能变成同一个值
                }
                nums.push_back(grid[i][j]);
            }
        }
        
        // 2. 排序找中位数
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        
        // 3. 计算所有数到中位数的步数之和
        long long operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }
        
        return (int)operations;
    }
};