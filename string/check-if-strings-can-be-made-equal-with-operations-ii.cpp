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
            if(s1[i] != s2[i]) return false;
        }
        return s1==s2;
    }
};

//第二种方法
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
//第三种方法
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        vector<int> s1_even(26,0);
        vector<int> s1_odd(26,0);
        vector<int> s2_even(26,0);
        vector<int> s2_odd(26,0);

        for(int i = 0;i < n;i++)
        {
            if(i%2==0)
            {
                s1_even[s1[i]-'a']++;
                s2_even[s2[i]-'a']++;
            }
            else{
                s1_odd[s1[i]-'a']++;
                s2_odd[s2[i]-'a']++;
            }
        }
        for(int i = 0;i < n;i++)
        {
            if(s1_even[i]!=s1_even[i]||s1_odd[i]!=s2_odd[i])
                return false;
        }
        return true;

    }
};
如果两个索引之间的差值为偶数，则意味着这两个索引必须具有完全相同的奇偶性。
也就是说，您可以将任意偶数索引处的字符与任意另一个偶数索引处的字符交换位置。
类似地，您可以将任意奇数索引处的字符与任意另一个奇数索引处的字符交换位置。
