class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int wood[128];
        int max_v = 0;
        for(int i = 0;i < 128;i++) wood[i] = -1;
        
        for(int right = 0;right < s.length();++right)
        {
            if(wood[s[right]] >= left)
                left = wood[s[right]] + 1;
            wood[s[right]] = right;
            max_v = max(max_v,right - left +1);             
        }
        return max_v;
        
    }
};