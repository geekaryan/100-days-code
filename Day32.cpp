// 485. Max Consecutive Ones
// Given a binary array nums, return the maximum number of consecutive 1's in the array.

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {

        int n = nums.size();
        int maxi = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                count = 0;
            }
            else
            {
                count = count + 1;
                maxi = max(maxi, count);
                cout << count << " ";
            }
        }

        return maxi;
    }
};