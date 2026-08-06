class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
        {
            return 0;
        }

        vector<bool> isPrime(n, true);
        vector<int> primes;

        int count = 0;

        for (long long i = 2; i < n; i++)
        {
            if (isPrime[i] == true)
            {
                count++;
                for (long long j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        return count;
    }
};