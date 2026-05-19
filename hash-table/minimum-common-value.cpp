// class Solution {
// public:
//     int Bs(vector<int> n,int target)
//     {
//         int l = 0;
//         int r = n.size() - 1;

//         while(l<=r)
//         {
//             int m = l + (r - l) / 2;
//             if(n[m] == target)
//                 return m;
//             else if(n[m] < target)
//                 l = m + 1;
//             else    
//                 r = m - 1;
//         }
//         return -1;
//     }

//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();

//         for(int i = 0;i < n1;i++)
//         {
//             int idx = Bs(nums2, nums1[i]);
//             if(idx != -1 && nums1[i] == nums2[idx])
//                 return nums1[i];
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                return nums1[i]; // 找到了，直接就是最小的
            } else if (nums1[i] < nums2[j]) {
                i++; // nums1 当前的值小了，往后移
            } else {
                j++; // nums2 当前的值小了，往后移
            }
        }
        return -1;
    }
};