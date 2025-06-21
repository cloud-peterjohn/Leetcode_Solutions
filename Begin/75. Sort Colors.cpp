// https://leetcode.com/problems/sort-colors/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        unordered_map<int, int> map;
        // count
        for (auto x : nums)
        {
            map[x]++;
        }
        // 填充原数组
        int idx = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < map[i]; ++j)
            {
                nums[idx] = i;
                ++idx;
            }
        }
    }
};