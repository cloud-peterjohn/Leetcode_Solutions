// https://leetcode.com/problems/contains-duplicate-ii/

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int left = 0, right = 0; // [left, right)
        unordered_set<int> window_set;
        while (right < nums.size())
        {
            if (window_set.find(nums[right]) != window_set.end())
                return true;
            window_set.insert(nums[right++]);
            if (right - left > k)
            {
                // 缩小窗口使其大小始终不超过k
                window_set.erase(nums[left++]);
            }
        }
        return false;
    }
};