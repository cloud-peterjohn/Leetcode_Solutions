// https://leetcode.com/problems/edit-distance/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        // dp_table[i, j]存储word1[i...]变为word2[j...]的编辑距离
        vector<vector<int>> dp_table(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // word2为空串，应对word1[i...]全部删除
        for (int i = 0; i < word1.size(); ++i)
            dp_table[i][word2.size()] = word1.size() - i;
        // word1为空串，应对word1全部插入word2[i...]
        for (int i = 0; i < word2.size(); ++i)
            dp_table[word1.size()][i] = word2.size() - i;
        dp_table[word1.size()][word2.size()] = 0;

        // DP
        for (int i = word1.size() - 1; i >= 0; --i)
        {
            for (int j = word2.size() - 1; j >= 0; --j)
            {
                int dist1 = dp_table[i + 1][j] + 1;     // 对word1删除当前字符
                int dist2 = dp_table[i][j + 1] + 1;     // 对word1增加一个字符
                int dist3 = dp_table[i + 1][j + 1] + 1; // 对word1替换一个字符
                int dist4 = 999999;                     // 当前字符已匹配，无需操作
                if (word1[i] == word2[j])
                    dist4 = dp_table[i + 1][j + 1] + 0;

                dp_table[i][j] = min({dist1, dist2, dist3, dist4});
            }
        }
        return dp_table[0][0];
    }
};
