// https://leetcode.com/problems/remove-element/description/

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0, fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != val)
            {
                nums[slow++] = nums[fast]; // slow维护不为val的数组段的末尾
            }
            ++fast;
        }
        return slow;
    }
};