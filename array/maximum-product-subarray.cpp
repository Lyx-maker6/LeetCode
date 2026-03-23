class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_val = 0;
        vector<int> ans;
        int sum = 1;
        for(int i = 0;i < nums.size();i++)
        {
            sum *= nums[i];
            ans.push_back(sum);
        }
        for(int j = 0; j < ans.size()-1; j++)
        {
            if(ans[j] > max_val)
            {
                max_val=ans[j];
            }
        }
        return max_val;
    }
};