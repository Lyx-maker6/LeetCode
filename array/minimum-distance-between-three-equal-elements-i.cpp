class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if(n < 3)
            return -1;
        else if(n == 3)
        {
            if(nums[0] == nums[1] && nums[1]== nums[2])
                return 2 * (2 - 0);
            else
                return -1;
        }
        else{
            vector<int> res(3);
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
                                res[2]=k;
                                break;
                            }
                        }
                    }
                }
            }
            ans = 2 * (res[2] - res[0]);
            return ans;
        }
    }
};