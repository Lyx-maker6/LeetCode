class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n1 = s1.length();
        for(int i = 0,j = i+2;j < n1;i++,j++)
        {
            swap(s1[i],s1[j]);
            if(s1==s2)
                return true;
        }
        return false;
    }
};