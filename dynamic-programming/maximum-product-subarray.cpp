class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_val = nums[0];
        int min_val = nums[0];
        int ans = nums[0];

        for(int i = 1;i < nums.size(); i++)
        {
            int num = nums[i];

            if(num < 0)
                swap(max_val, min_val);
            
            max_val = max(num, num * max_val);
            min_val = min(num, num * min_val);
            ans = max(max_val, ans);
        }
        return ans;
    }
};