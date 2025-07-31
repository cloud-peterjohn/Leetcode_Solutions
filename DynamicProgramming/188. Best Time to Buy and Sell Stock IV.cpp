// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // dp_table[i][j][k]代表在第i天交易次数不超过j次并且k表示当前是否持有股票情况下的最大收益
        vector<vector<vector<int>>> dp_table(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        // base case
        for (int j = 0; j < k + 1; ++j)
        {
            dp_table[0][j][0] = 0;
            dp_table[0][j][1] = -999999;
        }
        for (int i = 0; i < n + 1; ++i)
        {
            dp_table[i][0][0] = 0;
            dp_table[i][0][1] = -999999;
        }
        // DP
        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 1; j < k + 1; ++j)
            {
                dp_table[i][j][0] = max(
                    dp_table[i - 1][j][0], dp_table[i - 1][j][1] + prices[i - 1]);
                dp_table[i][j][1] = max(
                    dp_table[i - 1][j][1], dp_table[i - 1][j - 1][0] - prices[i - 1]);
            }
        }
        return dp_table[n][k][0];
    }
};