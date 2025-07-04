// https://leetcode.com/problems/3sum/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 对数组排序
        sort(nums.begin(), nums.end(), less<int>());
        cout << nums[0] << " " << nums[1] << " " << nums[2] << " " << nums[3] << endl;
        // 遍历第一个数idx0
        int idx0 = 0, idx1 = 0, idx2 = 0;
        vector<vector<int>> result;
        while (idx0 < nums.size() - 2)
        {
            int num1 = nums[idx0];
            // 滑动窗口[idx1, idx2]
            idx1 = idx0 + 1;
            idx2 = nums.size() - 1;
            while (idx1 < idx2)
            {
                int num2 = nums[idx1];
                int num3 = nums[idx2];
                if (num1 + num2 + num3 == 0)
                {
                    result.push_back(vector<int>{num1, num2, num3});
                    // 跳过num2和num3的重复元素
                    while (idx1 < nums.size() && nums[idx1] == num2)
                        ++idx1;
                    while (idx2 < nums.size() && nums[idx2] == num3)
                        --idx2;
                }
                else if (num1 + num2 + num3 < 0)
                {
                    while (idx1 < nums.size() && nums[idx1] == num2)
                        ++idx1;
                }
                else if (num1 + num2 + num3 > 0)
                {
                    while (idx2 < nums.size() && nums[idx2] == num3)
                        --idx2;
                }
            }
            // 跳过num0的重复元素
            while (idx0 < nums.size() && nums[idx0] == num1)
                ++idx0;
        }
        return result;
    }
};