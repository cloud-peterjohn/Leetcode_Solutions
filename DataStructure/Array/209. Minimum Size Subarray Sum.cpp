// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, right = 0, window_sum = 0, min_length = 900000;
        while (right < nums.size())
        {
            window_sum += nums[right++];
            while (left < right && window_sum >= target)
            {
                min_length = min(min_length, right - left);
                window_sum -= nums[left++];
            }
        }
        if (min_length == 900000)
            return 0;
        else
            return min_length;
    }
};