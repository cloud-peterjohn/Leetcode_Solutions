// https://leetcode.com/problems/longest-common-subsequence/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // dp_table[i][j]存储text1[i...]和text2[j...]之间的最长公共子序列的长度
        vector<vector<int>> dp_table(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = text1.size() - 1; i >= 0; --i)
        {
            for (int j = text2.size() - 1; j >= 0; --j)
            {
                if (text1[i] == text2[j])
                {
                    // 当前字符是公共的，位于公共子序列中
                    dp_table[i][j] = dp_table[i + 1][j + 1] + 1;
                }
                else
                {
                    int seq1 = dp_table[i + 1][j];     // text1[i]是非公共的
                    int seq2 = dp_table[i][j + 1];     // text2[j]是非公共的
                    int seq3 = dp_table[i + 1][j + 1]; // text1[i]和text2[j]完全不匹配
                    dp_table[i][j] = max({seq1, seq2, seq3});
                }
            }
        }
        return dp_table[0][0];
    }
};