// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

class Solution
{
private:
    int min_char_num(const unordered_map<char, int> &map)
    {
        int min_num = 10000;
        for (const auto &pair : map)
        {
            if (pair.second != 0)
                min_num = min(min_num, pair.second);
        }
        if (min_num == 10000)
            return 0;
        return min_num;
    }
    int char_count(const unordered_map<char, int> &map)
    {
        int count = 0;
        for (const auto &pair : map)
        {
            if (pair.second != 0)
                count += 1;
        }
        return count;
    }
    int get_longest_substring(string s, int k, int count)
    {
        // 求每个字符都出现至少`k`次且仅包含`count`种不同字符的最长子串
        int left = 0, right = 0, longest_substring = 0;
        unordered_map<char, int> map;
        while (right < s.size())
        {
            map[s[right++]]++;
            while (left < right && char_count(map) > count)
            { // 超出字符种类数量限制，缩小窗口
                map[s[left++]]--;
            }
            if (min_char_num(map) >= k && char_count(map) <= count)
            {
                longest_substring = max(longest_substring, right - left);
            }
        }
        return longest_substring;
    }

public:
    int longestSubstring(string s, int k)
    {
        int longest_substring = 0;
        for (int count = 1; count <= 26; ++count)
        {
            longest_substring = max(longest_substring, get_longest_substring(s, k, count));
        }
        return longest_substring;
    }
};