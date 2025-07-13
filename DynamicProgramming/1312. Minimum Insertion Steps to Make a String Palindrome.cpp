// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution
{
public:
    int minInsertions(string s)
    {
        // s[i..j]
        vector<vector<int>> dp_table(s.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < s.size(); ++j)
            { // j > i
                if (s[i] == s[j])
                {
                    dp_table[i][j] = dp_table[i + 1][j - 1];
                }
                else
                {
                    dp_table[i][j] = min(dp_table[i][j - 1], dp_table[i + 1][j]) + 1;
                }
            }
        }
        return dp_table[0][s.size() - 1];
    }
};
