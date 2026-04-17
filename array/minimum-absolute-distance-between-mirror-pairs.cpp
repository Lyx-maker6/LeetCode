class Solution {
public:
    int reverse(int x)
    {
        int ans = 0;
        while(x)
        {
            int tp = x % 10;
            x /= 10;
            if(tp == 0)
                continue;
            ans = ans * 10 + tp;
        }
        return ans;
    }

    
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int flag = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = i + 1;j < n; j++)
            {
                int tp = reverse(nums[i]);

                if(tp == nums[j])
                {
                    flag = 1;
                    if(abs(i - j) ==1)
                    {
                        cnt++;
                    }
                }
            }
        }
        if(flag) return cnt;
        else return -1;
        
    }
};