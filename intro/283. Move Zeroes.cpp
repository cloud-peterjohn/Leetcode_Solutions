// https://leetcode.com/problems/move-zeroes/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0;
        for (auto num : nums)
        {
            if (num != 0)
                nums[slow++] = num;
        }
        for (; slow < nums.size(); ++slow)
        {
            nums[slow] = 0;
        }
    }
};