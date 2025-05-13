// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.size() < p.size())
            return vector<int>{};

        int idx = 0;
        int length = p.size();
        vector<int> result;

        unordered_map<char, int> s_dict, p_dict;
        for (char ch : p)
            ++p_dict[ch];
        for (int i = 0; i < length; ++i)
            ++s_dict[s[i]];

        while (idx <= s.size() - length)
        {
            // 判断是否是anagrams
            bool is_anagram = true;
            for (auto pairs : p_dict)
            {
                if (s_dict[pairs.first] != pairs.second)
                {
                    is_anagram = false;
                    break;
                }
            }
            if (is_anagram)
                result.push_back(idx);

            // 窗口右移
            --s_dict[s[idx]];
            if (idx < s.size() - length)
                ++s_dict[s[idx + length]];
            ++idx;
        }
        return result;
    }
};