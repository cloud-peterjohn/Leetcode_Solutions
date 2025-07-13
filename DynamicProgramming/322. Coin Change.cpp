// https://leetcode.com/problems/coin-change/

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // 使用[0, coins.size()]种硬币，达到[0, amount]的金额
        vector<vector<int>> dp_table(coins.size() + 1, vector<int>(amount + 1, 0));
        // 只用0种硬币，一定凑不出
        for (int i = 1; i <= amount; ++i)
            dp_table[0][i] = 999999;
        // 金额为0，只需要0个硬币
        for (int i = 0; i <= coins.size(); ++i)
            dp_table[i][0] = 0;

        // DP
        for (int i = 1; i <= coins.size(); ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                // 不使用第i种硬币
                int num_coins1 = dp_table[i - 1][j];
                // 使用第i种硬币，且可以重复使用
                int num_coins2 = 999999;
                if (j - coins[i - 1] >= 0)
                    num_coins2 = dp_table[i][j - coins[i - 1]] + 1; // i从1开始
                dp_table[i][j] = min(num_coins1, num_coins2);
            }
        }
        if (dp_table[coins.size()][amount] == 999999)
            return -1;
        else
            return dp_table[coins.size()][amount];
    }
};