// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> dict;
        int left = 0, right = 0; // 左闭右开
        int max_len = 0;
        while (right < s.size())
        {
            // 窗口扩大
            ++right;
            ++dict[s[right - 1]];
            // 判断有无重复字符
            bool no_duplicate = true;
            for (auto pairs : dict)
            {
                if (pairs.second > 1)
                {
                    no_duplicate = false;
                    break;
                }
            }
            while ((!no_duplicate) && (left < right))
            {
                // 窗口缩小
                ++left;
                --dict[s[left - 1]];
                // 判断有无重复字符
                no_duplicate = true;
                for (auto pairs : dict)
                {
                    if (pairs.second > 1)
                    {
                        no_duplicate = false;
                        break;
                    }
                }
            }
            if ((right - left) > max_len)
                max_len = right - left;
        }
        return max_len;
    }
};