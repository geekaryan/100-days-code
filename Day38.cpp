// 1446. Consecutive Characters
// The power of the string is the maximum length of a non-empty substring that contains only one unique character.

// Given a string s, return the power of s.

class Solution
{
public:
    int maxPower(string s)
    {
        int n = s.length();
        int count = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != s[i + 1])
            {
                count = 0;
            }
            else
            {
                count++;
                maxi = max(maxi, count);
            }
        }

        return maxi + 1;
    }
};