// https://leetcode.com/problems/distinct-subsequences/

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        // 虚拟一行一列
        vector<vector<int>> dp_table(s.size() + 1, vector<int>(t.size() + 1, 0));
        // j == t.size()时，t[j:]为空串，已经匹配完
        for (int i = 0; i <= s.size(); ++i)
        {
            dp_table[i][t.size()] = 1;
        }
        // 在s[i...]中，t[j...]的出现次数
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = t.size() - 1; j >= 0; --j)
            {
                if (s[i] == t[j])
                {
                    // s[i]可以选，也可以跳过
                    dp_table[i][j] = dp_table[i + 1][j + 1] + dp_table[i + 1][j];
                }
                else
                {
                    // s[i]只能跳过
                    dp_table[i][j] = dp_table[i + 1][j];
                }
            }
        }
        return dp_table[0][0];
    }
};