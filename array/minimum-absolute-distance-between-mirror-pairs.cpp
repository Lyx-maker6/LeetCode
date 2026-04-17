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
        // for(int i = 0;i < n;i++)
        // {
        //     int tp = reverse(nums[i]);

        //     for(int j = i + 1;j < n; j++)
        //     {
        //         if(tp == nums[j])
        //         {
        //             min_v = min(min_v,abs(i - j));            
        //         }
        //     }
        // }
        // return (min_v == INT_MAX)? -1 : min_v;
        
        // key: 数值, value: 该数值最后出现的下标
        unordered_map<int, int> last_seen_val;
        // key: 反转后的值, value: 产生该反转值的原数下标
        unordered_map<int, int> last_seen_rev;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int rev = reverse(val);

            // 情况 A：当前的 nums[i] 刚好是之前某个 nums[p] 的反转
            // 即：reverse(nums[p]) == nums[i]
            if (last_seen_rev.count(val)) {
                min_v = min(min_v, i - last_seen_rev[val]);
            }
            
            // 情况 B：之前的某个 nums[p] 刚好是当前 nums[i] 的反转
            // 即：nums[p] == reverse(nums[i])
            if (last_seen_val.count(rev)) {
                min_v = min(min_v, i - last_seen_val[rev]);
            }

            // 更新当前数值及其反转值的最新位置
            last_seen_val[val] = i;
            last_seen_rev[rev] = i;
        }

        return (min_v == INT_MAX) ? -1 : min_v;
    }
};