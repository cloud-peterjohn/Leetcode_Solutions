// https://leetcode.com/problems/burst-balloons/

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        // nums[-1] = nums[n] = 1
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        // DP table: dp[i][j]表示戳破(i, j)开区间内的所有气球可以获得的最高分数
        vector<vector<int>> dp_table(n, vector<int>(n, 0));
        // base case: j <= i + 1，由于已经全部初始化为0不再需要处理

        // DP
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 2; j < n; ++j)
            {
                for (int k = i + 1; k < j; ++k)
                {
                    // 最后戳破气球k的得分
                    int score = dp_table[i][k] + dp_table[k][j] + nums[i] * nums[k] * nums[j];
                    dp_table[i][j] = max(dp_table[i][j], score);
                }
            }
        }
        return dp_table[0][n - 1];
    }
};