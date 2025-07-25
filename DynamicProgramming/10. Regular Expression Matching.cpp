// https://leetcode.com/problems/regular-expression-matching/

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        // `dp_table[i][j]`表示，对于字符串`s[i:]`和模式串`p[j:]`，能否正则匹配成功
        vector<vector<bool>> dp_table(m + 1, vector<bool>(n + 1, false));
        // base case: 模式串已匹配完，j == p.size()
        dp_table[m][n] = true;
        // base case: 目标串已匹配完，i == s.size()
        for (int j = n - 1; j >= 0; --j)
        {
            // a*b*c*d*的形式
            if (j + 1 < n && p[j + 1] == '*')
            {
                dp_table[m][j] = dp_table[m][j + 2];
            }
        }
        // DP
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                bool result = false;
                // 下一个模式字符为*
                if (j + 1 < n && p[j + 1] == '*')
                {
                    // 如果当前字符成功匹配
                    if (s[i] == p[j] || p[j] == '.')
                    {
                        // 匹配0次
                        result = result || dp_table[i][j + 2];
                        // 匹配多次
                        result = result || dp_table[i + 1][j];
                    }
                    //  如果当前字符不匹配，只能匹配0次
                    result = result || dp_table[i][j + 2];
                }
                // 当前字符匹配或当前模式字符为.
                if (s[i] == p[j] || p[j] == '.')
                    result = result || dp_table[i + 1][j + 1];

                dp_table[i][j] = result;
            }
        }
        if (m == 1 && n == 3)
            cout << dp_table[1][1];
        return dp_table[0][0];
    }
};