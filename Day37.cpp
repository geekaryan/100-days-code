// 392. Is Subsequence
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

class Solution
{
    bool solve(string s, string t, int m, int n)
    {
        if (m == 0)
        {
            return true;
        }
        if (n == 0)
        {
            return false;
        }

        if (s[m - 1] == t[n - 1])
        {
            return solve(s, t, m - 1, n - 1);
        }

        return solve(s, t, m, n - 1);
    }

public:
    bool isSubsequence(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        if (solve(s, t, m, n))
        {
            return true;
        }

        return false;
    }
};