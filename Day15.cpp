// 372. Super Pow
// Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

class Solution
{
public:
    int bin(int a, int b, int m)
    {
        a %= m;
        int ans = 1;
        while (b > 0)
        {
            if (b & 1)
            {
                ans = (ans * 1LL * a) % m;
            }
            a = (a * 1LL * a) % m;
            b >>= 1;
        }
        return ans;
    }
    int superPow(int a, vector<int> &b)
    {

        int n = b.size();
        int modi = 0;

        for (int i = 0; i < n; i++)
        {
            modi = (modi * 10 + b[i]) % 1140;
        }

        return bin(a, modi, 1337);
    }
};