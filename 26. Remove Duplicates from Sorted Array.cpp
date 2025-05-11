// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int new_idx = 0;
        for (int idx = 0; idx < nums.size(); ++idx)
        { // 快指针进行遍历
            if (nums[idx] != nums[new_idx])
            {
                nums[++new_idx] = nums[idx]; // 慢指针维护nums[0..idx]无重复
            }
        }
        return new_idx + 1;
    }
};