// 2461. Maximum Sum of Distinct Subarrays With Length K
// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        long long maxValue = 0, sum = 0;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums[i]) == 0)
            { // get sum of each window unique element
                sum += nums[i];
            }
            mp[nums[i]]++;
            if (mp.size() == k)
            {
                maxValue = max(maxValue, sum);
            }
            if (i - (k - 1) >= 0)
            {
                mp[nums[i - (k - 1)]]--;
                if (mp[nums[i - (k - 1)]] == 0)
                {
                    sum -= nums[i - (k - 1)];
                    mp.erase(nums[i - (k - 1)]);
                }
            }
        }

        return maxValue;
    }
};