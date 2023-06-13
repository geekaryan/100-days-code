// 2352. Equal Row and Column Pairs
// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int k;
        vector<int> ans;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                k = 0;
                while (k < n && grid[row][k] == grid[k][col])
                {
                    k++;
                }
                if (k >= n)
                {
                    count++;
                }
            }
        }

        return count;
    }
};