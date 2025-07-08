// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // 计算前缀和
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            prefix[i + 1] = nums[i] + prefix[i];
        }
        // 遍历子数组
        int subarray_num = 0;
        unordered_map<int, int> map; // 存储前缀和值以及对应的出现次数
        map[0] = 1;                  // 前缀和为0只出现了一次
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.find(prefix[i + 1] - k) != map.end())
            {
                // 区间(map[prefix[i + 1] - k], i + 1]，但map[prefix[i + 1]可能对应多个索引位置
                subarray_num += map[prefix[i + 1] - k];
            }
            // 先计数目标区间，再++map[prefix[i + 1]]：避免将空区间(i + 1, i + 1]计入
            ++map[prefix[i + 1]]; // 计数加一
        }
        return subarray_num;
    }
};