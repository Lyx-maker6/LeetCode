class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();

        int max_v = 0;

        // for(int i = 0;i < l1;i++)
        // {
        //     int d = 0;
        //     for(int j = 0;j < l2;j++)
        //     {
        //         if(nums1[i] <= nums2[j] && i <= j)
        //         {
        //             d = j - i;
        //             max_v = max(max_v, d);
        //         }
        //     }
        // }

        int i = 0;
        int j = 0;

        while(i < l1 && j < l2)
        {
            if(nums1[i] <= nums2[j])
            {
                max_v = max(max_v, j - i);
                j++;
            }
            else{
                i++;

                //优化：i 增加后，j 没必要重置，因为 i <= j 且之前的 j 已经测试过了
                if (i > j) j = i;
            }
        }

        return max_v;
    }
};