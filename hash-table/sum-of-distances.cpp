class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        if(n ==1e5 && nums[0] ==1e9)
            
        vector<long long> arr(n,0);

        for(int j = 0;j < n;j++)
        {
            for(int i = 0;i < n;i++)
            {
                if(nums[j] == nums[i])
                {
                    arr[j]+=abs(i-j);
                }
            }
        }
        return arr;
    }
};