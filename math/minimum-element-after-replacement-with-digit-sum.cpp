class Solution {
public:
    int mySum(int x){
        if(x==0) return 0;
        int sum = 0;
        int temp = x;
        while(x)
        {
            temp = x % 10;
            sum += temp; 
            x/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;
        for(int i= 0;i < nums.size();i++)
        {
            int num = mySum(nums[i]);
            min_val = min(min_val, num);
        }

        return min_val;
    }
};