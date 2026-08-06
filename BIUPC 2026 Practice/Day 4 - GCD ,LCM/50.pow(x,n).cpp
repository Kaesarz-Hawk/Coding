class Solution
{
public:
    double myPow(double x, int n)
    {
        bool negative = false;

        if (n < 0)
        {
            negative = true;
            n = -n;
        }

        double res = 1.0;

        while (n > 0)
        {
            if (n & 1)
                res *= x;

            x *= x;
            n >>= 1;
        }

        if (negative)
            return 1.0 / res;

        return res;
    }
};