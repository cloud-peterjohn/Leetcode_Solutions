// https://leetcode.com/problems/valid-palindrome/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // 大小写转换+去除其他字符
        string s1;
        for (const auto ch : s)
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                s1.push_back(ch - ('A' - 'a'));
            }
            else if (ch >= 'a' && ch <= 'z')
            {
                s1.push_back(ch);
            }
            else if (ch >= '0' && ch <= '9')
            {
                s1.push_back(ch);
            }
        }

        // 判断回文
        int left = 0, right = s1.size() - 1;
        bool is_palindrome = true;
        while (left <= right)
        {
            if (s1[left] != s1[right])
            {
                is_palindrome = false;
                break;
            }
            ++left;
            --right;
        }
        return is_palindrome;
    }
};