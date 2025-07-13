// https://leetcode.com/problems/russian-doll-envelopes/

class Solution
{
private:
    struct Compare
    {
        bool operator()(const vector<int> &envelope1, const vector<int> &envelope2)
        {
            if (envelope1[0] != envelope2[0])
            {
                // 对宽度按照升序排列，使用小于比较器
                return envelope1[0] < envelope2[0];
            }
            else
            {
                // 宽度相同，则对高度按照降序排列
                return envelope1[1] > envelope2[1];
            }
        }
    };
    int LIS(const vector<int> &height)
    {
        vector<int> dp_table(height.size(), 1);
        for (int i = 0; i < dp_table.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (height[j] < height[i])
                {
                    dp_table[i] = max(dp_table[i], dp_table[j] + 1);
                }
            }
        }
        int longest_increasing_subsequence = 0;
        for (int i = 0; i < dp_table.size(); ++i)
        {
            longest_increasing_subsequence = max(longest_increasing_subsequence, dp_table[i]);
        }
        return longest_increasing_subsequence;
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // 按宽度升序排列，如果宽度一样，则按高度降序排列
        sort(envelopes.begin(), envelopes.end(), Compare());
        // 对height求最长严格递增子序列
        vector<int> height;
        for (const auto envelope : envelopes)
            height.push_back(envelope[1]);
        return LIS(height);
    }
};