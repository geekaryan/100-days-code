// 560. Subarray Sum Equals K
// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = k;

        unordered_map<int, int> prevSum;

        int res = 0;
        int currSum = 0;

        for (int i = 0; i < n; i++)
        {

            currSum += nums[i];

            if (currSum == sum)
                res++;

            if (prevSum.find(currSum - sum) != prevSum.end())
                res += (prevSum[currSum - sum]);

            prevSum[currSum]++;
        }

        return res;
    }
};