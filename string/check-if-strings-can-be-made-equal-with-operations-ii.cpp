class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        for(int i = 0;i < n;i++)
        {
            if (s1[i] == s2[i]) continue;
            for(int j = i + 2;j < n;j +=2)
            {
                if(s1[j] == s2[i]){
                    swap(s1[i],s1[j]);
                    break;
                }
                    
    
            }
            
        }
        return s1==s2;
    }
};