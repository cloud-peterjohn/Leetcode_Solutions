// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution
{
public:
    string reverseWords(string s)
    {
        // 双指针：去除前导/尾部空格/重复空格
        int slow = 0, fast = 0;
        while (fast < s.size() && s[fast] == ' ')
            ++fast; // 前导0
        while (fast < s.size())
        { // 拷贝一个单词
            while (fast < s.size() && s[fast] != ' ')
                s[slow++] = s[fast++];
            while (fast < s.size() && s[fast] == ' ')
                ++fast; // 重复0和后导0
            s[slow++] = ' ';
        }
        s = s.substr(0, slow - 1);

        // elppa na si siht
        reverse(s.begin(), s.end());
        // apple an is this
        int left_idx = 0, right_idx = 0;
        while (right_idx < s.size())
        {
            if (s[right_idx] == ' ')
            {
                // reverse [left_idx, right_idx)
                reverse(s.begin() + left_idx, s.begin() + right_idx);
                left_idx = right_idx + 1;
            }
            ++right_idx;
        }
        reverse(s.begin() + left_idx, s.begin() + right_idx);

        return s;
    }
};