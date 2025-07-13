// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp_table(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (word1[i] == word2[j])
                {
                    dp_table[i][j] = dp_table[i + 1][j + 1] + 1;
                }
                else
                {
                    dp_table[i][j] = max({dp_table[i + 1][j], dp_table[i][j + 1], dp_table[i + 1][j + 1]});
                }
            }
        }
        return word1.size() + word2.size() - dp_table[0][0] * 2;
    }
};