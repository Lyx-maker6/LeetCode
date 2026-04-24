class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
///////////////////////////////////////////直接AI////////////////////////////////////////////////////
        int l_cnt = 0; // 记录 L 的数量
        int r_cnt = 0; // 记录 R 的数量
        int free_cnt = 0; // 记录 _ 的数量
        
        for (char c : moves) {
            if (c == 'L') l_cnt++;
            else if (c == 'R') r_cnt++;
            else free_cnt++;
        }
        
        // 情况 1：所有自由步都往左走，最终位置 = (r_cnt - l_cnt) - free_cnt
        // 情况 2：所有自由步都往右走，最终位置 = (r_cnt - l_cnt) + free_cnt
        // 我们取绝对值的最大值
        return max(abs(r_cnt - l_cnt - free_cnt), abs(r_cnt - l_cnt + free_cnt));
    }
};