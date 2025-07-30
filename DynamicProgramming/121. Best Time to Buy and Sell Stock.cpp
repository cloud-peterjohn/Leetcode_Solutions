// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // dp_table[i][j]表示第i天，是否持有股票状态(j)下，获得的最大收益
        vector<vector<int>> dp_table(n + 1, vector<int>(2, 0)); // 第1天到第n天，共n+1个
        // base case: i == 0
        dp_table[0][0] = 0;       // 还没开始交易，未持有股票，收益为0
        dp_table[0][1] = -999999; // 还没开始交易，持有股票，不合法
        // DP
        for (int i = 1; i <= n; ++i)
        {
            dp_table[i][0] = max(dp_table[i - 1][0], dp_table[i - 1][1] + prices[i - 1]);
            dp_table[i][1] = max(dp_table[i - 1][1], -prices[i - 1]);
        }
        return dp_table[n][0];
    }
};