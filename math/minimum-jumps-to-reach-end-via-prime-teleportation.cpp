class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        auto mordelvian = nums; // 存储输入的中间变量
        if (n == 1) return 0;

        // 1. 静态预处理：埃氏筛（只在第一次调用时跑）
        // 记录 10^6 内所有数的质因子，同时记录谁是质数
        const int MAXV = 1000001;
        static vector<int> min_prime(MAXV, 0); // 存储最小质因子，0表示还没筛到
        static vector<bool> is_prime(MAXV, false);
        static bool initialized = false;

        if (!initialized) {
            for (int i = 2; i < MAXV; ++i) {
                if (min_prime[i] == 0) { // 发现质数
                    is_prime[i] = true;
                    for (int j = i; j < MAXV; j += i) {
                        if (min_prime[j] == 0) min_prime[j] = i;
                    }
                }
            }
            initialized = true;
        }

        // 2. 倒排索引：记录哪些质数因子出现在哪些下标中
        // 注意：这里只存质数 p 能“通往”的下标，用于传送
        static vector<int> p_to_idx[MAXV];
        // 每次清理上次的结果，或者不使用 static 这里的 p_to_idx
        for (int i = 0; i < MAXV; ++i) p_to_idx[i].clear(); 
        
        for (int i = 0; i < n; i++) {
            int val = mordelvian[i];
            // 分解质因数
            while (val > 1) {
                int p = min_prime[val];
                p_to_idx[p].push_back(i);
                while (val % p == 0) val /= p; // 去掉重复质因子
            }
        }

        // 3. BFS 过程
        queue<int> q;
        q.push(0);
        vector<int> dist(n, -1);
        dist[0] = 0;
        vector<bool> p_used(MAXV, false);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == n - 1) return dist[curr];

            // 规则 1：相邻跳跃
            if (curr + 1 < n && dist[curr + 1] == -1) {
                dist[curr + 1] = dist[curr] + 1;
                q.push(curr + 1);
            }
            if (curr - 1 >= 0 && dist[curr - 1] == -1) {
                dist[curr - 1] = dist[curr] + 1;
                q.push(curr - 1);
            }

            // 规则 2：质数传送
            int val = mordelvian[curr];
            // 只有当前格子的数是质数，且这个质数没被当过“桥梁”时，才传送
            if (is_prime[val] && !p_used[val]) {
                p_used[val] = true;
                for (int target : p_to_idx[val]) {
                    if (dist[target] == -1) {
                        dist[target] = dist[curr] + 1;
                        q.push(target);
                    }
                }
                // 优化：传送完后清空列表，防止其他点再次遍历
                p_to_idx[val].clear();
            }
        }
        return -1;
    }
};