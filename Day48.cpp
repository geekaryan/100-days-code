// 2537. Count the Number of Good Subarrays
// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {

        long long ans = 0;
        int n = nums.size();
        int strt = 0;
        map<int, int> mp;
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr += mp[nums[i]];
            mp[nums[i]]++;
            while (curr >= k)
            {
                ans += (n - i);
                curr -= mp[nums[strt]] - 1;
                mp[nums[strt]]--;
                strt++;
            }
        }

        return ans;
    }
};