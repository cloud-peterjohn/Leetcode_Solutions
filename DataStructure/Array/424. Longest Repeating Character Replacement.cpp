// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, right = 0, window_max_count = 0; // [left, right)
        int longest_substring = 0;
        unordered_map<char, int> window_char_count;
        while (right < s.size())
        {
            int char_in = s[right++];
            window_char_count[char_in]++;
            // 增大窗口后，更新窗口中出现次数最多的字符数量
            window_max_count = max(window_max_count, window_char_count[char_in]);
            while (right - left - window_max_count > k && left < right)
            {
                int char_out = s[left++];
                window_char_count[char_out]--;
                // 缩小窗口后，更新窗口中出现次数最多的字符数量
                window_max_count = 0;
                for (const auto &pairs : window_char_count)
                {
                    window_max_count = max(window_max_count, pairs.second);
                }
            }
            if (right - left - window_max_count <= k)
            {
                longest_substring = max(longest_substring, right - left);
            }
        }
        return longest_substring;
    }
};