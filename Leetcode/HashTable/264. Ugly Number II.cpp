//Tc- 0(n)
//sc- 0(n)
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> ugly_num(n);
        int i2 = 0, i3 = 0, i5 = 0;
        ugly_num[0] = 1;

        if(n<0) return 0;
        if(n<1) return 1;

        for(int i = 1; i < n; i++)
        {
            int by2 = ugly_num[i2]*2;
            int by3 = ugly_num[i3]*3;
            int by5 = ugly_num[i5]*5;
            ugly_num[i] = min({by2,by3,by5});

            if(ugly_num[i] == by2) i2++;
            if(ugly_num[i] == by3) i3++;
            if(ugly_num[i] == by5) i5++;
        }

        return ugly_num[n-1];

    }
};
