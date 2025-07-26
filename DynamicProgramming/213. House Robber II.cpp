// https://leetcode.com/problems/house-robber-ii/

class Solution
{
private:
    int house_robber(const vector<int> &nums, const int begin, const int end)
    {
        int length = end - begin + 1;
        // dp_table[i]代表抢劫nums范围[begin + i, begin + length - 1]可以获得的最大金额
        vector<int> dp_table(length + 1, 0);
        // base case: [begin + length, begin + length - 1]，无房屋可抢
        dp_table[length] = 0;
        // base case: [begin + length - 1, begin + length - 1]，只能抢最后一个
        dp_table[length - 1] = nums[begin + length - 1];
        // DP
        for (int i = length - 2; i >= 0; --i)
        {
            dp_table[i] = max(
                // 抢当前房屋
                nums[begin + i] + dp_table[i + 2],
                // 不抢当前房屋
                dp_table[i + 1]);
        }
        return dp_table[0];
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0]; // 避免n-2越界
        // 对于首尾房屋，一定不抢劫尾部房屋
        int rob_first = house_robber(nums, 0, n - 2);
        // 对于首尾房屋，一定不抢劫尾部房屋
        int rob_last = house_robber(nums, 1, n - 1);
        return max(rob_first, rob_last);
    }
};