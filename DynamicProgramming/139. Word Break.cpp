// https://leetcode.com/problems/word-break/

// 回溯算法
class Solution
{
    bool backtrack(const string &target, const vector<string> &word_dict, vector<string> &track, int &length)
    {
        // track内的字符串长度已超
        if (length > target.size())
            return false;
        // 成功匹配
        bool is_word_match = true;
        int idx_target = 0;
        for (const auto word : track)
        {
            for (int idx_word = 0; idx_word < word.size(); ++idx_word)
            {
                if (target[idx_target] != word[idx_word])
                {
                    // 字符未匹配
                    is_word_match = false;
                    break;
                }
                idx_target++;
            }
            if (is_word_match == false)
                break;
        }
        // 当全部匹配，且字符数一样时（不仅仅是前缀匹配）
        if (is_word_match && length == target.size())
            return true;

        // 回溯
        for (int i = 0; i < word_dict.size(); ++i)
        {
            track.push_back(word_dict[i]);
            length += word_dict[i].size();
            bool is_match = backtrack(target, word_dict, track, length);
            if (is_match)
                return true;
            track.pop_back();
            length -= word_dict[i].size();
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> track;
        int length = 0;
        return backtrack(s, wordDict, track, length);
    }
};

// 动态规划

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // dp_table[i]表示s[i...]可以被wordDict匹配
        vector<bool> dp_table(s.size() + 1, false);
        dp_table[s.size()] = true; // 空串s可以被任意wordDict匹配
        // 如果单词word可以匹配s[...k]，那仅需继续判断s[k+1...]
        for (int i = s.size() - 1; i >= 0; --i)
        {
            bool is_match = false;
            for (const auto word : wordDict)
            {
                if (i + word.size() <= s.size() && s.substr(i, word.size()) == word)
                {
                    is_match = dp_table[i + word.size()];
                    if (is_match)
                        break;
                }
            }
            dp_table[i] = is_match;
        }
        return dp_table[0];
    }
};