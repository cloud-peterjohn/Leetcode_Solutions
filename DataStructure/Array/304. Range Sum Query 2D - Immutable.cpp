// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix
{
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefix_sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        this->prefix = prefix_sum;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return this->prefix[row2 + 1][col2 + 1] - (this->prefix[row1][col2 + 1] + this->prefix[row2 + 1][col1] - this->prefix[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */