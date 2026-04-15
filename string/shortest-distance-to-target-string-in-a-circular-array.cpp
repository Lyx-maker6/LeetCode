class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for(int i = 0;i < n; i++)
        {
            if(words[i] == target)
            {
                int d = abs(i - startIndex);//正向距离
                int re_d = n - d;//向左的距离
                ans = min(min(d,re_d),ans);

            }
                
        }

        if(ans != INT_MAX) return ans;
        else return -1;
    }
};