// 53. Maximum Subarray
// Given an integer array nums, find the
// subarray
//  with the largest sum, and return its sum.

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int maxi = INT_MIN, maxe = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            maxe += nums[i];
            if (maxi < maxe)
            {
                maxi = maxe;
            }
            if (maxe < 0)
            {
                maxe = 0;
            }
        }

        return maxi;
    }
};