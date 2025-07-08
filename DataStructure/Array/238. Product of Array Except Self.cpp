// https://leetcode.com/problems/product-of-array-except-self/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // 前缀积
        vector<int> prefix(nums.size() + 1, 1);
        for (int i = 1; i <= nums.size(); ++i)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        // 后缀积
        vector<int> suffix(nums.size() + 1, 1);
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            suffix[i] = suffix[i + 1] * nums[i];
        }
        // 计算answer
        vector<int> answer(nums.size());
        for (int i = 0; i < answer.size(); ++i)
        {
            answer[i] = prefix[i] * suffix[i + 1];
        }
        return answer;
    }
};