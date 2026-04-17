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

        
        // 只需要一个备忘录：记录数值 -> 最后出现的下标
        unordered_map<int, int> last_seen;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int rev = reverse(val);

            // 核心修正：对称性检查
            // 只有当“反转再反转”能回到原值时，这个数才可能拥有镜像
            if (reverse(rev) == val) {
                // 检查它的镜像（rev）之前是否出现过
                if (last_seen.count(rev)) {
                    min_v = min(min_v, i - last_seen[rev]);
                }
            }

            // 无论是否匹配，都记录当前数值出现的位置
            last_seen[val] = i;
        }

        return (min_v == INT_MAX) ? -1 : min_v;
    }
};