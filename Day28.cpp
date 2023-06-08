// 1351. Count Negative Numbers in a Sorted Matrix
// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {

        int r = grid.size();
        int c = grid[0].size();

        int count = 0;

        for (int row = 0; row < r; row++)
        {
            for (int col = 0; col < c; col++)
            {
                if (grid[row][col] < 0)
                {
                    count++;
                }
            }
        }

        return count;
    }
};