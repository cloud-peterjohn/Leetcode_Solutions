// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        // dp_table[i][j]存储使得s1[i..]和s2[j..]变得相同的，需要删除的字符最小ASCII码之和
        vector<vector<int>> dp_table(m + 1, vector<int>(n + 1, 0));
        // 如果s1[i..]和s2[j..]均为空，无需删除字符
        dp_table[m][n] = 0;
        // 如果s2[j..]为空，删除s1全部字符
        for (int i = m - 1; i >= 0; --i)
        {
            dp_table[i][n] = dp_table[i + 1][n] + int(s1[i]);
        }
        // 如果s1[i..]为空，删除s2全部字符
        for (int j = n - 1; j >= 0; --j)
        {
            dp_table[m][j] = dp_table[m][j + 1] + int(s2[j]);
        }

        // DP
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (s1[i] == s2[j])
                {
                    // 字符匹配，则无需删除
                    dp_table[i][j] = dp_table[i + 1][j + 1];
                }
                else
                {
                    int del1 = dp_table[i + 1][j] + s1[i];
                    int del2 = dp_table[i][j + 1] + s2[j];
                    int del3 = dp_table[i + 1][j + 1] + s1[i] + s2[j];
                    dp_table[i][j] = min({del1, del2, del3});
                }
            }
        }
        return dp_table[0][0];
    }
};