// https://leetcode.com/problems/continuous-subarray-sum/

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        // 计算前缀和
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            prefix[i + 1] = nums[i] + prefix[i];
        }
        // 遍历子数组
        unordered_map<int, int> map;
        map[0] = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            // 记录第一次出现prefix[i + 1] % k的值的索引
            if (map.find(prefix[i + 1] % k) == map.end())
            {
                map[prefix[i + 1] % k] = i + 1;
            }
            // 找到目标区间(map[prefix[i + 1] % k], i + 1]
            else
            {
                int length = i + 1 - map[prefix[i + 1] % k];
                if (length >= 2)
                    return true;
            }
        }
        return false;
    }
};