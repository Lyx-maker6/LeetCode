class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int x=0,y=0,z=0;
        int cnt = 0;
        for(int i = 0;i < arr.size(); i++)
        {
            for(int j = i+1;j < arr.size();j++)
            {
                for(int k = j+1;k < arr.size();k++)
                {
                    x=fabs(arr[i] - arr[j]);
                    y=fabs(arr[j] - arr[k]);
                    z=fabs(arr[i] - arr[k]);
                    if(x <= a && y <= b && z <= c)
                    {
                        cnt++;
                    }

                }
            }
        }
        return cnt;
    }
};