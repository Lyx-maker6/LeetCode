class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        for(int i = 0;i < n;i++)
        {
            vector<int> temp;
            int tp = nums[i];
            while(tp)
            {
                temp.push_back(tp % 10);
                tp/=10;
            }

            for(int j = temp.size() - 1; j >= 0; j--)
            {
                ans.push_back(temp[j]);
            }
        }

        return ans;
    }
};