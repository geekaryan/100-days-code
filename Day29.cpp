// 744. Find Smallest Letter Greater Than Target
// You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

// Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {

        int l = 0;
        int r = letters.size() - 1;
        int mid = 0;
        if (letters[r] <= target)
        {
            return letters[0];
        }

        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (letters[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return letters[l];
    }
};