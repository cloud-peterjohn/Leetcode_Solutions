// https://leetcode.com/problems/count-sub-islands/

class Solution
{
private:
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n)
        {
            return;
        }
        if (grid[i][j] == 0)
        {
            return;
        }

        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size(), n = grid1[0].size();
        // 淹掉一定不是子岛屿的岛屿
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1 && grid1[i][j] == 0)
                {
                    dfs(grid2, i, j);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1)
                {
                    res++;
                    dfs(grid2, i, j);
                }
            }
        }
        return res;
    }
};