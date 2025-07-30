// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        // dp_table[i][j]表示第i天，是否持有股票状态(j)下，获得的最大收益
        vector<vector<int>> dp_table(n + 1, vector<int>(2, 0)); // 避免访问i-1时越界
        // base case
        dp_table[0][0] = 0;
        dp_table[0][1] = -999999;
        // DP
        for (int i = 1; i < n + 1; ++i)
        {
            dp_table[i][0] = max(dp_table[i - 1][0], dp_table[i - 1][1] + prices[i - 1]);
            dp_table[i][1] = max(dp_table[i - 1][1], dp_table[i - 1][0] - prices[i - 1] - fee); // 买入手续费
        }
        return dp_table[n][0];
    }
};
