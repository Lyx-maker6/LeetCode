class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
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
                                int d = 2 * (k - i);
                                if(ans == -1 || d < ans)
                                {
                                    ans = d;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            return ans;
        }
    }
};