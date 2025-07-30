// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // dp_table[i][j]表示第i天，是否持有股票状态(j)下，获得的最大收益
        vector<vector<int>> dp_table(n + 2, vector<int>(2, 0)); // 避免访问i-2时越界
        // base case
        dp_table[0][0] = 0, dp_table[1][0] = 0;
        dp_table[0][1] = -999999, dp_table[1][1] = -999999;
        // DP
        for (int i = 2; i < n + 2; ++i)
        {
            dp_table[i][0] = max(dp_table[i - 1][0], dp_table[i - 1][1] + prices[i - 2]);
            dp_table[i][1] = max(dp_table[i - 1][1], dp_table[i - 2][0] - prices[i - 2]); // 买入必须在卖出的后冷冻一天
        }
        return dp_table[n + 1][0];
    }
};