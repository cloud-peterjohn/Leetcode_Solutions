// https://leetcode.com/problems/super-egg-drop/

class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        // `dp_table[i][j]`表示从拥有`i`个鸡蛋，以及待尝试的`j`层楼，至少要扔几次鸡蛋才能确定临界楼层。
        vector<vector<int>> dp_table(k + 1, vector<int>(n + 1, 999999));
        // base case: 只有一个鸡蛋时和没有鸡蛋时
        dp_table[0][0] = 0;
        for (int j = 1; j <= n; ++j)
        {
            dp_table[1][j] = j;
            dp_table[0][j] = 999999;
        }
        // base case: 楼层数为0时
        for (int i = 1; i <= k; ++i)
        {
            dp_table[i][0] = 0;
        }
        // DP
        for (int i = 2; i <= k; ++i)
        { // 鸡蛋数从2开始，因为0和1都是base case
            for (int j = 1; j <= n; ++j)
            { // 楼层数
                int left = 1, right = j;
                while (left <= right)
                {
                    int mid = left + (right - left) / 2;
                    int break_egg = dp_table[i - 1][mid - 1];
                    int not_break_egg = dp_table[i][j - mid];
                    dp_table[i][j] = min(dp_table[i][j], 1 + max(break_egg, not_break_egg));
                    if (break_egg > not_break_egg)
                    {
                        // 更坏情况是摔碎鸡蛋，说明当前区间中值楼层太高，因此后续从更低楼层中搜索
                        right = mid - 1;
                    }
                    else
                    {
                        // 更坏情况是不摔碎鸡蛋，说明当前区间中值楼层太低，因此后续从更高楼层中搜索
                        left = mid + 1;
                    }
                }
            }
        }
        return dp_table[k][n];
    }
};