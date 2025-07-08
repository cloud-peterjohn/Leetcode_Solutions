// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

// 前缀和+哈希表
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        // 寻找`nums`中元素和为`sum(nums) - x`的最长连续子数组的长度
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            prefix[i + 1] = nums[i] + prefix[i];
        }
        int sum = prefix[prefix.size() - 1] - x;
        if (sum == 0)
            return nums.size(); // 全部取走，应返回n而不是0

        unordered_map<int, int> map;
        map[0] = 0;
        int max_length = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.find(prefix[i + 1]) == map.end())
            {
                map[prefix[i + 1]] = i + 1;
            }
            if (map.find(prefix[i + 1] - sum) != map.end())
            {
                // (map[prefix[i + 1] - sum], i + 1]
                max_length = max(max_length, i + 1 - map[prefix[i + 1] - sum]);
            }
        }
        if (max_length == 0)
            return -1;
        return nums.size() - max_length;
    }
};

// 滑动窗口
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        // 寻找`nums`中元素和为`sum(nums) - x`的最长连续子数组的长度
        int total_sum = 0;
        for (const auto num : nums)
            total_sum += num;
        int target = total_sum - x;
        if (target == 0)
            return nums.size(); // 全部取走，应返回n而不是0

        // 滑动窗口
        int max_length = 0;
        int window_sum = 0;
        int left = 0, right = 0; // window [left, right)
        while (right < nums.size())
        {
            window_sum += nums[right];
            ++right;
            while (left < right && window_sum > target)
            {
                window_sum -= nums[left];
                ++left;
            }
            if (window_sum == target)
            {
                max_length = max(max_length, right - left);
            }
        }
        if (max_length == 0)
            return -1;
        return nums.size() - max_length;
    }
};