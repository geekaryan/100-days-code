// 48. Rotate Image
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>> ans;
        vector<int> temp;

        for (int col = 0; col < c; col++)
        {
            for (int row = c - 1; row >= 0; row--)
            {
                temp.push_back(matrix[row][col]);
            }
            ans.push_back(temp);
            temp.clear();
        }

        matrix = ans;
    }
};