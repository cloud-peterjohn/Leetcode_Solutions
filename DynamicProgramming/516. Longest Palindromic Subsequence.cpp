// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        // dp_table[i][j]表示s[i..j]中的最长回文子序列
        vector<vector<int>> dp_table(s.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = 0; i < s.size(); ++i)
            dp_table[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < s.size(); ++j)
            {
                if (s[i] == s[j])
                {
                    dp_table[i][j] = dp_table[i + 1][j - 1] + 2;
                }
                else
                {
                    dp_table[i][j] = max(dp_table[i][j - 1], dp_table[i + 1][j]);
                }
            }
        }
        return dp_table[0][s.size() - 1];
    }
};
