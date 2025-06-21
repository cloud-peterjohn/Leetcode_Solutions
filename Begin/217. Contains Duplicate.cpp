// https://leetcode.com/problems/contains-duplicate

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> uset;
        for (const auto &num : nums)
        {
            if (uset.find(num) == uset.end())
            {
                uset.insert(num);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};