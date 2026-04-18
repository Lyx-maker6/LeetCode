class Solution {
public:
    int reverse(int x)
    {
        int ans = 0;
        while(x)
        {
            int tp = x % 10;
            x /= 10;
            ans = ans * 10 + tp;
        }
        return ans;
    }

    int mirrorDistance(int n) {
        int re_n = reverse(n);
        return abs(n - re_n);
    }
};