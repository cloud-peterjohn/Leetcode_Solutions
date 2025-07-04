// https://leetcode.com/problems/4sum/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return vector<vector<int>>{}; // 避免nums.size() - 3数值负溢出
        sort(nums.begin(), nums.end(), less<int>());
        vector<vector<int>> result;
        // 外部循环遍历
        int idx1 = 0;
        cout << nums.size() - 3 << " " << idx1 << endl;
        while (idx1 < nums.size() - 3)
        { // 注意：nums.size()返回size_t是无符号数，减为负就是溢出出错
            int num1 = nums[idx1];
            int idx2 = idx1 + 1;
            while (idx2 < nums.size() - 2)
            {
                int num2 = nums[idx2];
                // 滑动窗口
                int idx3 = idx2 + 1, idx4 = nums.size() - 1;
                while (idx3 < idx4)
                {
                    int num3 = nums[idx3], num4 = nums[idx4];
                    if (num1 + num2 + num3 + num4 == target)
                    {
                        result.push_back(vector<int>{num1, num2, num3, num4});
                        while (idx3 < nums.size() && nums[idx3] == num3)
                            idx3++;
                        while (idx4 < nums.size() && nums[idx4] == num4)
                            idx4--;
                    }
                    else if (num1 + num2 + num3 + num4 < target)
                    {
                        while (idx3 < nums.size() && nums[idx3] == num3)
                            idx3++;
                    }
                    else if (num1 + num2 + num3 + num4 > target)
                    {
                        while (idx4 < nums.size() && nums[idx4] == num4)
                            idx4--;
                    }
                }
                while (idx2 < nums.size() && nums[idx2] == num2)
                    idx2++;
            }
            while (idx1 < nums.size() && nums[idx1] == num1)
                idx1++;
        }
        return result;
    }
};