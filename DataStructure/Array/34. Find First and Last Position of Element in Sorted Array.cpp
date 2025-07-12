// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int target_idx = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                target_idx = mid;
                break;
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }

        if (target_idx == -1)
            return vector<int>{-1, -1};
        int left_bound = target_idx, right_bound = target_idx;
        while (left_bound < nums.size() && nums[left_bound] == target)
            left_bound--;
        while (right_bound < nums.size() && nums[right_bound] == target)
            right_bound++;
        return vector<int>{left_bound + 1, right_bound - 1};
    }
};