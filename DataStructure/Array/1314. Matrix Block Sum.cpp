// https://leetcode.com/problems/matrix-block-sum/

class Solution
{
private:
    int get_prefix(vector<vector<int>> &prefix, int i, int j)
    {
        // 防止越界访问：特别注意size()返回无符号整数，如果i为负数会比较出错
        if (i >= int(prefix.size()))
            i = prefix.size() - 1;
        if (j >= int(prefix[0].size()))
            j = prefix[0].size() - 1;
        if (i < 0)
            i = 0;
        if (j < 0)
            j = 0;
        return prefix[i][j];
    }

public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        // 计算前缀和
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        // 填充answer
        vector<vector<int>> answer(m, vector<int>(n, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                answer[i - 1][j - 1] = get_prefix(prefix, i + k, j + k) - (get_prefix(prefix, i - k - 1, j + k) + get_prefix(prefix, i + k, j - k - 1) - get_prefix(prefix, i - k - 1, j - k - 1));
            }
        }
        return answer;
    }
};