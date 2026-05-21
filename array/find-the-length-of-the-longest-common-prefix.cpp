class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        // 1. 将 arr1 中所有数字的所有前缀存入哈希表
        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10; // 不断去掉最后一位，得到更短的前缀
            }
        }

        int max_len = 0;

        // 2. 遍历 arr2，检查其前缀是否在哈希表中存在
        for (int val : arr2) {
            while (val > 0) {
                if (prefixes.count(val)) {
                    // 如果在哈希表中找到了公共前缀
                    // 计算这个前缀的数位长度（利用 to_string 算长度最直观）
                    int current_len = to_string(val).length();
                    max_len = max(max_len, current_len);
                    
                    // 剪枝优化：因为我们是从长到短剥离前缀的，
                    // 只要当前数字在哈希表里匹配到了，它一定是这个数字能提供的最长前缀，
                    // 接下来的更短前缀就没必要再查了，直接看 arr2 的下一个数。
                    break; 
                }
                val /= 10;
            }
        }

        return max_len;
    }
};