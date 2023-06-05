// 378. Kth Smallest Element in a Sorted Matrix
// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                ans.push_back(matrix[row][col]);
            }
        }

        sort(ans.begin(), ans.end());
        int s = ans.size();
        for (int i = 0; i < s; i++)
        {
            if (i == k - 1)
            {
                return ans[i];
            }
        }

        return -1;
    }
};