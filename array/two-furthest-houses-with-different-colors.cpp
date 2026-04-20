class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int max_v = 0;

        for(int i = 0;i  < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                if(colors[i] != colors[j])
                {
                    int d = j - i;
                    max_v = max(max_v,d);
                }
            }
        }

        return max_v;
    }
};