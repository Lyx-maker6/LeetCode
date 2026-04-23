// class Solution {
// public:
//     vector<long long> distance(vector<int>& nums) {
//         int n = nums.size();

//         vector<long long> arr(n,0);

//         for(int j = 0;j < n;j++)
//         {
//             for(int i = 0;i < n;i++)
//             {
//                 if(nums[j] == nums[i])
//                 {
//                     arr[j]+=abs(i-j);
//                 }
//             }
//         }
//         return arr;
//     }
// };
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        // 1. 分组存储：key 是数值，value 是这个数值出现的所有下标
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }

        // 2. 遍历每个分组计算距离
        for (auto& [val, pos] : groups) {
            int m = pos.size();
            if (m < 2) continue; // 只有一个数，距离为 0

            // 计算该组下标的总和，用于后续求右侧和
            long long total_sum = 0;
            for (int p : pos) total_sum += p;

            long long left_sum = 0;
            for (int i = 0; i < m; i++) {
                long long current_p = pos[i];
                // 右侧下标之和 = 总和 - 左侧之和 - 当前下标
                long long right_sum = total_sum - left_sum - current_p;

                // 左侧贡献：i * current_p - left_sum
                // 右侧贡献：right_sum - (m - 1 - i) * current_p
                arr[current_p] = (i * current_p - left_sum) + 
                                 (right_sum - (long long)(m - 1 - i) * current_p);

                left_sum += current_p; // 更新左侧和供下一个点使用
            }
        }
        return arr;
    }
};//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////依旧不会////////////////////////////////////////////////////////////////