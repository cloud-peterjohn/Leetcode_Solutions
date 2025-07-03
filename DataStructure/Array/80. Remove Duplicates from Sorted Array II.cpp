// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        while (fast < nums.size())
        {
            bool is_valid = true;
            if (slow - 1 >= 0 && nums[slow - 1] == nums[fast])
            {
                if (slow - 2 >= 0 && nums[slow - 2] == nums[fast])
                {
                    is_valid = false;
                }
            }
            if (is_valid)
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};