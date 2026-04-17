class Solution {
public:
    int reverse(int x)
    {
        int ans = 0;
        while(x)
        {
            int tp = x % 10;
            x /= 10;
            ans = ans * 10 + tp;
        }
        return ans;
    }

    
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int min_v = INT_MAX;
        for(int i = 0;i < n;i++)
        {
            int tp = reverse(nums[i]);

            for(int j = i + 1;j < n; j++)
            {
                if(tp == nums[j])
                {
                    min_v = min(min_v,abs(i - j));            
                }
            }
        }
        return (min_v == INT_MAX)? -1 : min_v;
        
    }
};