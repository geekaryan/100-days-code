// 413. Arithmetic Slices
//     An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

//     For example,
//     [ 1, 3, 5, 7, 9 ], [ 7, 7, 7, 7 ], and[ 3, -1, -5, -9 ] are arithmetic sequences.Given an integer array nums, return the number of arithmetic subarrays of nums.

//     A subarray is a contiguous subsequence of the array.

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        int cd;
        for (int i = 0; i <= n - 3; i++)
        {
            cd = nums[i + 1] - nums[i];
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] - nums[j - 1] == cd)
                {
                    if ((j - i + 1) >= 3)
                    {
                        count++;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return count;
    }
};