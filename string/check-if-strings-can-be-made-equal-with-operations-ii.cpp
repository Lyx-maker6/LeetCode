class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        string res = s1;
        for(int i = 0;i < n;i++)
        {
            for(int j = 1;j < n;j++)
            {
                if((j-i)%2==0)
                    swap(res[i],res[j]);
                if(res==s2)
                    return true;
            }
            
        }
        return false;
    }
};