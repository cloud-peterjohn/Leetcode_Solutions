// https://leetcode.com/problems/dungeon-game/

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size(), n = dungeon[0].size();
        // 从[i, j]走到终点[m - 1, n - 1]所需要的最小生命值
        vector<vector<int>> dp_table(m, vector<int>(n, 0));
        // 初始化
        dp_table[m - 1][n - 1] = (-dungeon[m - 1][n - 1]) + 1;
        if (dp_table[m - 1][n - 1] <= 0)
            dp_table[m - 1][n - 1] = 1;
        for (int i = m - 2; i >= 0; --i)
        {
            // 最右一列
            dp_table[i][n - 1] = dp_table[i + 1][n - 1] - dungeon[i][n - 1];
            if (dp_table[i][n - 1] <= 0)
                dp_table[i][n - 1] = 1;
        }
        for (int j = n - 2; j >= 0; --j)
        {
            // 最下一行
            dp_table[m - 1][j] = dp_table[m - 1][j + 1] - dungeon[m - 1][j];
            if (dp_table[m - 1][j])
                dp_table[m - 1][j] = 1;
        }
        // DP
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j = n - 2; j >= 0; --j)
            {
                // DP
                int right = dp_table[i][j + 1] - dungeon[i][j];
                int down = dp_table[i + 1][j] - dungeon[i][j];
                dp_table[i][j] = min(down, right);
                // 当前位置点有足够的魔法球
                if (dp_table[i][j] <= 0)
                    dp_table[i][j] = 1;
            }
        }
        return dp_table[0][0];
    }
};