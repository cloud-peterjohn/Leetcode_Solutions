// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        vector<vector<int>> dp_table(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (i == 0)
                {
                    dp_table[i][j] = matrix[i][j];
                }
                else
                {
                    int left_top = 9999, top = 9999, right_top = 9999;
                    if (i - 1 >= 0 && j - 1 >= 0)
                        left_top = dp_table[i - 1][j - 1];
                    if (i - 1 >= 0)
                        top = dp_table[i - 1][j];
                    if (i - 1 >= 0 && j + 1 <= dp_table[0].size() - 1)
                        right_top = dp_table[i - 1][j + 1];
                    dp_table[i][j] = matrix[i][j] + min(min(left_top, top), right_top);
                }
            }
        }
        int min_path_sum = 99999;
        for (int i = 0; i < dp_table[0].size(); ++i)
        {
            min_path_sum = min(min_path_sum, dp_table[dp_table.size() - 1][i]);
        }
        return min_path_sum;
    }
};