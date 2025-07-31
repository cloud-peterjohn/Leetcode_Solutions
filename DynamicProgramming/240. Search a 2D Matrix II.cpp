// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                --j; // 向左移动，元素减小
            else
                ++i; // 向右移动，元素增大
        }
        return false;
    }
};