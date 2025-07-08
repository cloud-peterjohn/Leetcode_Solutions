// https://leetcode.com/problems/find-pivot-index/

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        // 计算前缀和
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        // 遍历寻找中心点
        for (int i = 0; i < nums.size(); ++i)
        {
            int left = prefix[i];
            int right = prefix[prefix.size() - 1] - prefix[i + 1];
            if (left == right)
                return i;
        }
        return -1;
    }
};