// https://leetcode.com/problems/single-number/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> uset;
        for (const auto &num : nums)
        {
            uset[num]++;
        }
        for (const auto &pairs : uset)
        {
            if (pairs.second == 1)
            {
                return pairs.first;
            }
        }
        return -1;
    }
};