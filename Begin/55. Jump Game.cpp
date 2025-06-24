// https://leetcode.com/problems/jump-game/

// 动态规划
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<bool> dp_table(nums.size(), false);
        // 迭代遍历
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int distance = nums.size() - 1 - i;
            // 当curr_index = i时，dp_table[i]记录是否能够跳至终点
            if (nums[i] >= distance)
            {
                // 足够一次性直接跳跃至终点
                dp_table[i] = true;
            }
            else
            {
                for (int j = 1; j <= nums[i]; ++j)
                {
                    // 可以通过多次跳跃到达终点
                    if (i + j < nums.size() && dp_table[i + j])
                    {
                        dp_table[i] = true;
                        break;
                    }
                }
            }
        }
        return dp_table[0];
    }
};

// 贪心算法
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int max_steps = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (max_steps < i + nums[i])
                max_steps = i + nums[i];
            if (max_steps <= i)
                return false; // 中间存在0，导致无法前进
        }
        cout << max_steps << endl;
        if (max_steps >= nums.size() - 1)
            return true; // 可以到达最后面
        else
            return false;
    }
};
