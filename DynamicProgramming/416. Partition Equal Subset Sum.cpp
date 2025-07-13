// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int capacity = 0;
        for (const auto num : nums)
            capacity += num;
        if (capacity % 2 != 0)
            return false;
        capacity /= 2;

        // i从1开始，所以n+1；j除了重量1~capacity以外还有0，所以capacity + 1
        vector<vector<bool>> dp_table(n + 1, vector<bool>(capacity + 1, false));
        for (int i = 0; i <= n; ++i)
            dp_table[i][0] = true;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= capacity; ++j)
            {
                bool not_put = dp_table[i - 1][j];
                bool put_in = false;
                if (j - nums[i - 1] >= 0)
                    put_in = dp_table[i - 1][j - nums[i - 1]];

                if (not_put || put_in)
                    dp_table[i][j] = true;
                else
                    dp_table[i][j] = false;
            }
        }

        return dp_table[n][capacity];
    }
};