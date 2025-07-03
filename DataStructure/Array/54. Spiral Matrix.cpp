// https://leetcode.com/problems/spiral-matrix/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        if (matrix.size() == 0)
            return result;

        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (result.size() < m * n)
        {
            // 从左至右
            if (top <= bottom)
            {
                for (int i = left; i <= right; ++i)
                {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            // 从上至下
            if (left <= right)
            {
                for (int i = top; i <= bottom; ++i)
                {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            // 从右至左
            if (top <= bottom)
            {
                for (int i = right; i >= left; --i)
                {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // 从下至上
            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};