// 1004. Max Consecutive Ones III
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int i = 0, j = 0, zeroCounter = 0, ans = INT_MIN;

        while (j < nums.size())
        {
            if (nums[j] == 0)
                zeroCounter++;
            while (zeroCounter > k)
            {
                if (nums[i] == 0)
                    zeroCounter--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};