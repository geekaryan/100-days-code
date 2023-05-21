// 2679. Sum in a Matrix
// You are given a 0-indexed 2D integer array nums. Initially, your score is 0. Perform the following operations until the matrix becomes empty:

// From each row in the matrix, select the largest number and remove it. In the case of a tie, it does not matter which number is chosen.
// Identify the highest number amongst all those removed in step 1. Add that number to your score.
// Return the final score.

class Solution
{
public:
    int matrixSum(vector<vector<int>> &nums)
    {

        int r = nums.size();
        int c = nums[0].size();

        int ans = 0;

        for (int i = 0; i < r; i++)
        {
            sort(nums[i].begin(), nums[i].end());
        }

        for (int col = 0; col < c; ++col)
        {
            int maxi = 0;
            for (int row = 0; row < r; ++row)
            {
                maxi = max(maxi, nums[row][col]);
            }
            ans += maxi;
        }

        return ans;
    }
};