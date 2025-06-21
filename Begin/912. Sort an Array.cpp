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

// 快速排序
class Solution
{
public:
    int partition(vector<int> &nums, int begin, int end)
    {
        // 随机选一个pivot，将小于pivot的元素放到其左边，大于pivot的元素放到其右边
        int pivot = nums[int((begin + end) / 2)];
        swap(nums[int((begin + end) / 2)], nums[end]);
        int j = begin; // j记录已经分割好的小于pivot的元素最右端位置
        for (int i = begin; i < end; ++i)
        { // i用于遍历
            if (nums[i] < pivot)
            {
                swap(nums[i], nums[j]);
                ++j;
            }
        }
        swap(nums[j], nums[end]); // 将pivot放到最终的中间位置
        return j;                 // 返回pivot的索引
    }

    void sort(vector<int> &nums, int begin, int end)
    {
        if (begin >= end)
            return;
        int p = partition(nums, begin, end);
        sort(nums, begin, p - 1);
        sort(nums, p + 1, end);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};