// https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof

class Solution
{
public:
    vector<int> twoSum(vector<int> &price, int target)
    {
        int left = 0;
        int right = price.size() - 1;
        while (left < right)
        {
            int sum = price[left] + price[right];
            if (sum == target)
            {
                return vector<int>{price[left], price[right]};
            }
            else if (sum > target)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }
        return vector<int>{0, 0};
    }
};