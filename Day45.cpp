// 2750. Ways to Split Array Into Good Subarrays

// You are given a binary array nums.

// A subarray of an array is good if it contains exactly one element with the value 1.

// Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.

// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution
{
    int mod = 1e9 + 7;

public:
    int numberOfGoodSubarraySplits(vector<int> &nums)
    {
        vector<int> lit;
        long mod3 = 1000000007L;
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            if (nums[i] == 1)
            {
                lit.push_back(i);
            }
        }

        long ans = 0;

        if (lit.size() > 0)
        {
            ans = 1;
        }

        long dpans = ans;

        for (int i = lit.size() - 2; i >= 0; i--)
        {
            int leftInd = lit[i];
            int rightInd = lit[i + 1];

            int df = rightInd - leftInd;
            long mul = ((long)df % mod3 * (long)dpans % mod3) % mod3;
            dpans = mul;
            ans = mul;
        }

        return (int)ans;
    }
};