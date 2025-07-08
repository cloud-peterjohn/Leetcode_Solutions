// https://leetcode.com/problems/subarray-product-less-than-k/

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        // [left, right)
        int left = 0, right = 0, product = 1, num_arrays = 0;
        while (right < nums.size())
        {
            product *= nums[right++];
            while (product >= k && left < right)
            {
                product /= nums[left++];
            }
            if (product < k)
            {
                // 不能是++num_arrays;
                // [left...right), [left+1...right), [left+2...right), ..., [right - 1, right)等都是满足要求的数组，共计(right - 1) - (left) + 1个
                num_arrays += right - left;
            }
        }
        return num_arrays;
    }
};