class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        // 1. 特判：如果起点本来就是 0，直接到终点
        if (arr[start] == 0) return true;

        // 2. 队列用于 BFS，visited 数组用于防死循环
        queue<int> q;
        vector<bool> visited(n, false);

        // 3. 起点入队并标记
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // 如果当前位置的值是 0，说明找到了！
            if (arr[curr] == 0) return true;

            // 计算往右跳和往左跳的下一个下标
            int next_right = curr + arr[curr];
            int next_left = curr - arr[curr];

            // 检查右跳是否合法（不出界且没走过）
            if (next_right < n && !visited[next_right]) {
                visited[next_right] = true;
                q.push(next_right);
            }

            // 检查左跳是否合法（不出界且没走过）
            if (next_left >= 0 && !visited[next_left]) {
                visited[next_left] = true;
                q.push(next_left);
            }
        }

        // 队列空了还没找到 0，说明无法到达
        return false;
    }
};