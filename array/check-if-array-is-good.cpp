class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n_plus_1 = nums.size();
        if (n_plus_1 < 2) return false; // base[n] 长度至少为 2 (base[1] = [1,1])

        // 1. 找到数组中的最大值
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }

        // 2. 检查长度是否符合 n + 1 的要求
        // 如果最大值是 n，长度必须是 n + 1
        if (max_val != n_plus_1 - 1) {
            return false;
        }

        // 3. 统计频率
        vector<int> count(max_val + 1, 0);
        for (int x : nums) {
            count[x]++;
        }

        // 4. 验证 base[n] 的频率规则
        // 检查 1 到 n-1 是否各出现一次
        for (int i = 1; i < max_val; i++) {
            if (count[i] != 1) return false;
        }

        // 检查最大值 n 是否出现了两次
        if (count[max_val] != 2) return false;

        return true;
    }
};