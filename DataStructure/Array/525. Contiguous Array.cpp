// https://leetcode.com/problems/contiguous-array/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        vector<int> prefix(nums.size() + 1, 0);
        // 0记录为-1， 1记录为1
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
                prefix[i + 1] = prefix[i] - 1;
            else
                prefix[i + 1] = prefix[i] + 1;
        }
        // 哈希表存储便于快速访问
        unordered_map<int, int> map;
        map[0] = 0;
        int max_len = 0;
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (map.find(prefix[i]) != map.end())
            {
                // 区间(prefix[i], i]
                max_len = max(max_len, i - map[prefix[i]]);
                // 不需要存入map[prefix[i]]=i，因为只需要记录每个值第一次出现的地方来获得最长子数组
            }
            else
            {
                map[prefix[i]] = i;
            }
        }
        return max_len;
    }
};