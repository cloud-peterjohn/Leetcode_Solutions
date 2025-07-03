// https://leetcode.com/problems/rotate-image/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // 以主对角线为轴翻转
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = i; j < matrix[i].size(); ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 对矩阵每行进行逆序
        for (auto &line : matrix)
        {
            reverse(line.begin(), line.end());
        }
    }
};