// https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // dp_table[i]表示以nums[i]为尾元素的元素和最大的子数组之和
        vector<int> dp_table(nums.size(), 0);
        dp_table[0] = nums[0];

        // DP
        for (int i = 1; i < nums.size(); ++i)
        {
            dp_table[i] = max(dp_table[i - 1] + nums[i], nums[i]);
        }

        // 返回最大的子数组元素和
        int max_subarray = 0;
        for (const int sum : dp_table)
            max_subarray = max(max_subarray, sum);
        return max_subarray;
    }
};