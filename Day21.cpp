// 2710. Remove Trailing Zeros From a String
// Given a positive integer num represented as a string, return the integer num without trailing zeros as a string.

class Solution
{
public:
    string removeTrailingZeros(string num)
    {

        int n = num.length();
        int i;
        for (i = n - 1; i >= 0; i--)
        {
            if (num[i] != '0')
            {
                break;
            }
        }

        return num.substr(0, i + 1);
    }
};