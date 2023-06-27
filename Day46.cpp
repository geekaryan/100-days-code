// 1835. Find XOR Sum of All Pairs Bitwise AND
// The XOR sum of a list is the bitwise XOR of all its elements. If the list only contains one element, then its XOR sum will be equal to this element.

// For example, the XOR sum of [1,2,3,4] is equal to 1 XOR 2 XOR 3 XOR 4 = 4, and the XOR sum of [3] is equal to 3.
// You are given two 0-indexed arrays arr1 and arr2 that consist only of non-negative integers.

// Consider the list containing the result of arr1[i] AND arr2[j] (bitwise AND) for every (i, j) pair where 0 <= i < arr1.length and 0 <= j < arr2.length.

// Return the XOR sum of the aforementioned list.

class Solution
{
public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2)
    {
        int first = 0;
        int second = 0;

        for (auto i : arr1)
        {
            first ^= i;
        }

        for (auto i : arr2)
        {
            second ^= i;
        }

        return (second & first);
    }
};