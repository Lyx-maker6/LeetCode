class Solution {
public:

    int isE(int n)
    {
        int flag = 0;
        while(n)
        {
            int d = n % 10;
            if(d == 3 || d == 4 || d == 7) return 0;
            if(d == 2 || d == 5 || d == 6 || d == 9) flag =1;
            n /= 10;
        }
        return flag;
    }

    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            if(isE(i))
                cnt++;
        }
        return cnt;
    }
};