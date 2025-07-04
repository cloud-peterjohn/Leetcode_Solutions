// https://leetcode.com/problems/longest-common-prefix/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix;
        int min_len = 99999;
        for (const string s : strs)
            min_len = min(min_len, int(s.size()));
        for (int i = 0; i < min_len; ++i)
        {
            char ch = strs[0][i];
            bool is_public_prefix = true;
            for (const string s : strs)
            {
                if (s[i] != ch)
                {
                    is_public_prefix = false;
                    break;
                }
            }
            if (is_public_prefix)
                prefix.push_back(ch);
            else
                break; // 避免找出后面的共同字符，而不在前缀部分
        }
        return prefix;
    }
};