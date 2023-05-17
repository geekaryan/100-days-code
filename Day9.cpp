// 345. Reverse Vowels of a String
// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

class Solution
{
public:
    string reverseVowels(string s)
    {

        int p = 0;
        int q = s.size() - 1;

        while (p <= q)
        {
            if (s[p] == 'a' || s[p] == 'e' || s[p] == 'i' || s[p] == 'o' || s[p] == 'u' || s[p] == 'A' || s[p] == 'E' || s[p] == 'I' || s[p] == 'O' || s[p] == 'U')
            {
                if (s[q] == 'a' || s[q] == 'e' || s[q] == 'i' || s[q] == 'o' || s[q] == 'u' || s[q] == 'A' || s[q] == 'E' || s[q] == 'I' || s[q] == 'O' || s[q] == 'U')
                {
                    swap(s[p++], s[q--]);
                }
                else
                {
                    q--;
                }
            }
            else
            {
                p++;
            }
        }

        return s;
    }
};