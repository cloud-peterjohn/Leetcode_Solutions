// https://leetcode.cn/problems/kLl5u1/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;
        while (right > left)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
                return vector<int>{left, right};

            if (sum < target)
                ++left;
            if (sum > target)
                --right;
        }
        return vector<int>{-1, -1};
    }
};