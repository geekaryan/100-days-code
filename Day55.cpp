// 1015. Smallest Integer Divisible by K
// Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

// Return the length of n. If there is no such n, return -1.

// Note: n may not fit in a 64-bit signed integer.

class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        int n = 0;
        int p = 0;
        for (int i = 1; i <= k; i++)
        {
            p = n * 10 + 1;
            n = p % k;
            if (n == 0)
            {
                return i;
            }
        }

        return -1;
    }
};