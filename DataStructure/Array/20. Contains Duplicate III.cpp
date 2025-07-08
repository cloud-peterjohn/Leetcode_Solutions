// https://leetcode.com/problems/contains-duplicate-iii/

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        int left = 0, right = 0; // [left, right)
        set<int> window;
        while (right < nums.size())
        {
            // 判断abs(nums[right] - nums[j]) <= valueDiff（在将nums[right]放入set之前判断以避免i==j）
            auto ceiling = window.lower_bound(nums[right]); // 略大于nums[right]的元素
            if (ceiling != window.end())
            {
                if (*ceiling <= nums[right] + valueDiff)
                {
                    return true;
                }
            }
            auto floor = window.lower_bound(nums[right]);
            if (floor != window.begin())
            {
                --floor; // 略小于nums[right]的元素
                if (*floor >= nums[right] - valueDiff)
                {
                    return true;
                }
            }
            window.insert(nums[right++]); // 如果是重复值则不发生任何变化
            // 缩小窗口使得abs(i - j) <= indexDiff
            while (right - left > indexDiff && left < right)
            {
                window.erase(nums[left++]);
            }
        }
        return false;
    }
};