// https://leetcode.com/problems/target-sum/

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum_of_nums = 0;
        for (const int num : nums)
            sum_of_nums += num;
        int sum = (sum_of_nums + target) / 2;
        // 不能整除
        if ((sum_of_nums + target) % 2 != 0)
            return 0;
        // target负太多导致sum为负数
        if (sum < 0)
            return 0;

        // dp_table[i][j]表示前i个数能够组成和为j的方案数
        vector<vector<int>> dp_table(nums.size() + 1, vector<int>(sum + 1, 0));
        // base case: 0个数，但和不为0，无此方案
        for (int i = 1; i <= sum; ++i)
            dp_table[0][i] = 0;
        // base case: 多个非负数，但和为0，无此方案
        for (int i = 1; i <= nums.size(); ++i)
            dp_table[i][0] = 0;
        // base case: 0个数，和为0，仅一种方案
        dp_table[0][0] = 1;

        // DP
        for (int i = 1; i <= nums.size(); ++i)
        {
            for (int j = 0; j <= sum; ++j)
            {
                // 不选nums[i]
                int plans1 = dp_table[i - 1][j];
                // 选nums[i]，不允许重复选
                int plans2 = 0;
                if (j - nums[i - 1] >= 0)
                    plans2 = dp_table[i - 1][j - nums[i - 1]]; // i从1开始
                dp_table[i][j] = plans1 + plans2;
            }
        }
        return dp_table[nums.size()][sum];
    }
};