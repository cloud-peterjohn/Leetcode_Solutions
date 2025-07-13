// https://leetcode.com/problems/word-break-ii/

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<vector<string>> dp_table(s.size() + 1, vector<string>{});
        // base case：匹配到s的末尾
        dp_table[dp_table.size() - 1] = vector<string>{""};
        for (int i = s.size() - 1; i >= 0; --i)
        {
            vector<string> v;
            for (const auto word : wordDict)
            {
                if (i + word.size() <= s.size() && s.substr(i, word.size()) == word)
                {
                    // 拼接当前word和与s[k...]匹配的所有字符串
                    for (const auto ss : dp_table[i + word.size()])
                        if (ss == "")
                            v.push_back(word);
                        else
                            v.push_back(word + " " + ss);
                }
            }
            dp_table[i] = v;
        }
        return dp_table[0];
    }
};