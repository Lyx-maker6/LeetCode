class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        string res = s1;
        for(int i = 0;i < n;i++)
        {
            if (res[i] == s2[i]) continue;
            for(int j = i+ 2;j < n;j +=2)
            {
                if(res[j] == s2[i])
                    swap(res[i],res[j]);
                if(res==s2)
                    return true;
            }
            
        }
        return false;
    }
};