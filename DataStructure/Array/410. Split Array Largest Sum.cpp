// https://leetcode.com/problems/split-array-largest-sum/

class Solution
{
private:
    int f(const vector<int> &nums, int max_sum)
    {
        // f()为单减函数
        // 将nums切分为子数组，每个子数组的元素和最多不超过max_sum，返回切分的最少子数组数量
        if (nums.size() == 0)
            return 0;
        int idx = 0, sum = 0, num_arrays = 1;
        while (idx < nums.size())
        {
            sum += nums[idx];
            if (sum > max_sum)
            {
                sum = nums[idx];
                num_arrays++;
            }
            idx++;
        }
        return num_arrays;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        // 搜索子数组元素和max_sum的左边界值，使得数组能够被分割为k个子数组
        // 自变量max_sum范围[left, right]
        int left = 0, right = 0;
        for (const auto num : nums)
        {
            left = max(left, num); // 子数组至少有一个元素，元素和至少为单个元素的最大值
            right += num;          // 元素和最多为全部元素之和
        }
        // 二分搜索左边界
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int num_subarray = f(nums, mid);
            if (num_subarray == k)
            {
                right = mid - 1;
            }
            else if (num_subarray > k)
            {
                // 单减函数，需要反过来
                left = mid + 1;
            }
            else if (num_subarray < k)
            {
                // 单减函数，需要反过来
                right = mid - 1;
            }
        }
        return left;
    }
};