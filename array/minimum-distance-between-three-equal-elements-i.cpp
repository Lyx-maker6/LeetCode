class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
         return -1;

        vector<int> res(3);
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = i + 1; j < n;j++)
            {
                if(nums[i] == nums[j])
                {
                    for(int k = j + 1;k < n;k++)
                    {
                        if(nums[j] == nums[k])
                        {
                            res[0]=i;
                            res[1]=j;
                            res[2]=k;
                            break;
                        }
                    }
                }
            }
        }

        ans = abs(res[0] - res[1]) + abs(res[1] - res[2]) + abs(res[2] - res[0]);
        return ans;

        
    }
};