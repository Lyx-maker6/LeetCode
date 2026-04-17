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


        // key: 前面某个数反转后的结果, value: 该数原本的下标
        unordered_map<int, int> rev_map;

        for (int j = 0; j < n; j++) {
            // 1. 检查当前的数，是否是前面某个数反转后的结果
            if (rev_map.count(nums[j])) {
                min_v = min(min_v, j - rev_map[nums[j]]);
            }

            // 2. 将当前数反转后的结果存入 map，供后面的数匹配
            // 注意：我们要找的是最小距离，所以如果反转值相同，更新为靠后的下标
            rev_map[reverse(nums[j])] = j;
        }

        return (min_v == INT_MAX) ? -1 : min_v;
    }
};