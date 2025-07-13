// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp_table(nums.size(), 1); // 存储以nums[i]结尾的严格单增子序列最大长度
        int longest_subsequence = 0;
        for (int i = 0; i < dp_table.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp_table[i] = max(dp_table[i], dp_table[j] + 1);
                }
            }
            longest_subsequence = max(longest_subsequence, dp_table[i]);
        }
        return longest_subsequence; // 返回dp_table中最大值，而不是最后一个元素
    }
};