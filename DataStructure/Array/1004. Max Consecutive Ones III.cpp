// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0, right = 0; // [left, right)
        int one_in_window = 0, longest_ones = 0;
        while (right < nums.size())
        {
            one_in_window += nums[right++];
            int zero_in_window = (right - left) - one_in_window;
            while (zero_in_window > k && left < right)
            { // 实际替换数量大于允许替换数量时，窗口缩小
                one_in_window -= nums[left++];
                zero_in_window = (right - left) - one_in_window;
            }
            if (zero_in_window <= k)
            {
                longest_ones = max(longest_ones, right - left);
            }
        }
        return longest_ones;
    }
};