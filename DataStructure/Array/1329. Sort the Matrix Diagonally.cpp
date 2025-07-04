// https://leetcode.com/problems/sort-the-matrix-diagonally/description/

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        if (mat.size() == 0)
            return vector<vector<int>>{vector<int>{}};
        int m = mat.size(), n = mat[0].size();
        int idx_i, idx_j;
        for (int i = 0; i < m + n - 1; ++i)
        {
            // 当前处理的对角线起始元素坐标
            if (i < m)
            {
                idx_i = i;
                idx_j = 0;
            }
            else
            {
                idx_i = 0;
                idx_j = i - (m - 1);
            }
            // 将该对角线上的所有元素装进vector
            vector<int> diagonal;
            while (idx_i < m && idx_j < n)
            {
                diagonal.push_back(mat[idx_i++][idx_j++]);
            }
            // 升序排序
            sort(diagonal.begin(), diagonal.end(), less<int>());
            // 将排序结果写回对角线
            if (i < m)
            {
                idx_i = i;
                idx_j = 0;
            }
            else
            {
                idx_i = 0;
                idx_j = i - (m - 1);
            }
            int sorted_idx = 0;
            while (idx_i < m && idx_j < n)
            {
                mat[idx_i++][idx_j++] = diagonal[sorted_idx++];
            }
        }
        return mat;
    }
};