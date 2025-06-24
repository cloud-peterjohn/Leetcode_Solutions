// https://leetcode.com/problems/jump-game-ii/

// 动态规划
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // 只有一个元素，跳跃0次
        if (nums.size() == 1)
            return 0;
        vector<int> hop(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int distance = nums.size() - 1 - i;
            // 一步直接到达
            if (nums[i] >= distance)
            {
                hop[i] = 1;
            }
            // 多步间接到达
            else
            {
                hop[i] = 99999;
                for (int j = 1; j <= nums[i]; ++j)
                {
                    hop[i] = min(1 + hop[i + j], hop[i]);
                }
            }
        }
        return hop[0];
    }
};

// 贪心算法
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // 只有一个元素，跳跃0次
        if (nums.size() == 1)
            return 0;
        // hopper步可以跳到区间[i, end]，区间内可以跳至最远farest索引处
        int hopper = 0, end = 0, farest = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        { // 数组最后一个元素不用管
            farest = max(farest, i + nums[i]);
            // [i, end]区间已遍历完，再跳一步
            if (i == end)
            {
                ++hopper;
                end = farest;
                // 到达终点
                if (farest >= nums.size() - 1)
                    return hopper;
            }
        }
        return -1;
    }
};