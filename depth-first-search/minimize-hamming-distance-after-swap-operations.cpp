class Solution {
public:
    // 1. 并查集查找函数（带路径压缩，比赛常用技巧）
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]); // 顺便把老大的老大直接改成终极老大
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i; // 初始化

        // 2. 合并所有连通的下标
        for (auto& s : allowedSwaps) {
            int rootA = find(parent, s[0]);
            int rootB = find(parent, s[1]);
            if (rootA != rootB) parent[rootA] = rootB; // 把它们连在一起
        }

        // 3. 把同一个朋友圈的 source 数字存进哈希表
        // Map 结构： 老大ID -> {数字 : 出现次数}
        unordered_map<int, unordered_map<int, int>> group_map;
        for (int i = 0; i < n; i++) {
            int root = find(parent, i);
            group_map[root][source[i]]++;
        }

        // 4. 遍历 target，看朋友圈里能不能提供它需要的数
        int diff = 0;
        for (int i = 0; i < n; i++) {
            int root = find(parent, i);
            int need = target[i];
            
            if (group_map[root][need] > 0) {
                group_map[root][need]--; // 朋友圈里有，直接拿来用
            } else {
                diff++; // 朋友圈里翻遍了也没这个数，只能贡献汉明距离
            }
        }

        return diff;
    }
};