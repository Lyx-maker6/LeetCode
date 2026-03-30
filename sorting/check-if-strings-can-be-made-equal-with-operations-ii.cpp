class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        string saa, sab, sba, sbb;
        for(int i = 0; i < n; ++i){
            if(i % 2 ==0){
                saa += s1[i];
                sba += s2[i];
            }
            else{
                sab += s1[i];
                sbb += s2[i];
            }
        }
        sort(saa.begin(), saa.end());
        sort(sba.begin(), sba.end());
        if(saa != sba)
            return false;
        sort(sab.begin(), sab.end());
        sort(sbb.begin(), sbb.end());
        if(sab != sbb)
            return false;
        return true;
    }
};