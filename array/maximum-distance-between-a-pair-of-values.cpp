class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();

        int max_v = INT_MIN;

        for(int i = 0;i < l1;i++)
        {
            int d = 0;
            for(int j = 0;j < l2;j++)
            {
                if(nums1[i] <= nums2[j] && i <= j)
                {
                    d = j - i;
                    max_v = max(max_v, d);
                }

            }
        }
        return max_v;
    }
};