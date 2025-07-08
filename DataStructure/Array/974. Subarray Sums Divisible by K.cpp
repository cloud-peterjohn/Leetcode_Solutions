// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            prefix[i + 1] = nums[i] + prefix[i];
        }
        unordered_map<int, int> map; // 记录前缀和值及其对应的出现次数
        map[0] = 1;
        int result_num = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.find((prefix[i + 1] % k + k) % k) != map.end())
            {
                result_num += map[(prefix[i + 1] % k + k) % k]; // 防止负数
            }
            ++map[(prefix[i + 1] % k + k) % k];
        }
        return result_num;
    }
};