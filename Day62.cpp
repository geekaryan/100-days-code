// 205. Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {

        int n = s.size();
        int m = t.size();

        if (n != m)
        {
            return false;
        }

        map<char, char> mp;
        set<char> set;

        for (int i = 0; i < n; i++)
        {
            char c1 = s[i];
            char c2 = t[i];

            if (mp.find(c1) != mp.end())
            {
                if (mp[c1] != c2)
                {
                    return false;
                }
            }
            else
            {

                if (set.find(c2) != set.end())
                {
                    return false;
                }

                mp[c1] = c2;
                set.insert(c2);
            }
        }

        return true;
    }
};