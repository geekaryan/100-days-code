// 287. Find the Duplicate Number
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
                break;
            }
        }

        return 0;
    }
};