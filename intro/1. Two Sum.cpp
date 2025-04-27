// https://leetcode.com/problems/two-sum

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int num1 = nums[i];
                int num2 = nums[j];
                if (num1 + num2 == target)
                {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>{0, 0};
    }
};