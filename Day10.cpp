// 74. Search a 2D Matrix
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size();    // row
        int c = matrix[0].size(); // col

        for (int row = 0; row < r; row++)
        {
            for (int col = 0; col < c; col++)
            {
                if (matrix[row][col] == target)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};