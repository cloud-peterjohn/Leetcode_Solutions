// https://leetcode.com/problems/number-of-islands/

class Solution
{
private:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        // 越界
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;
        // 如果是海水
        if (grid[i][j] == '0')
            return;
        // 变为海水，淹没岛屿
        grid[i][j] = '0';
        // 遍历邻居节点
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int num_islands = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    num_islands++;
                    // 淹没该岛屿
                    dfs(grid, i, j);
                }
            }
        }
        return num_islands;
    }
};