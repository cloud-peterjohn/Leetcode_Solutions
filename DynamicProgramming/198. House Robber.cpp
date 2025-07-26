// https://leetcode.com/problems/house-robber/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // dp_table[i]代表抢劫nums[i..]可以获得的最大金额
        vector<int> dp_table(n + 1, 0);
        // base case
        dp_table[n] = 0;               // 无房屋可抢
        dp_table[n - 1] = nums[n - 1]; // 抢劫最后一个房屋
        // DP
        for (int i = n - 2; i >= 0; --i)
        {
            dp_table[i] = max(
                // 抢当前房屋
                nums[i] + dp_table[i + 2],
                // 不抢当前房屋
                dp_table[i + 1]);
        }
        return dp_table[0];
    }
};