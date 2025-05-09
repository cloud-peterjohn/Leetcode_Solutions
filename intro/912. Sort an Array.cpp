// https://leetcode.com/problems/sort-an-array/

// 希尔排序
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        // 生成函数，取h有序数组的最大值h
        int h = 1;
        while (h < nums.size())
        {
            h = h * 3 + 1;
        }
        // 希尔排序，递增h值
        for (; h >= 1; h = (h - 1) / 3)
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                for (int j = i - h; j >= 0; j = j - h)
                {
                    if (nums[j] > nums[j + h])
                    {
                        swap(nums[j], nums[j + h]);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return nums;
    }
};