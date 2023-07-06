// 209. Minimum Size Subarray Sum
// Given an array of positive integers nums and a positive integer target, return the minimal length of a
// subarray
//  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (nums[i] + nums[j] >= target)
                {
                    count++;
                }
            }
        }

        return count;
    }
};