// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
    public:
        string findPalindrome(string s, int center1, int center2) {
            int left = center1, right = center2;
            if ((s[left] != s[right]) || (left < 0) || (right > s.size() - 1)) return "";
    
            while ((left >= 0) && (right <= s.size() - 1) && (s[left] == s[right])) {
                --left;
                ++right;
            }
            ++left;
            --right;
    
            int length = right - left + 1;
            string palindromic = s.substr(left, length);
            return palindromic;
        }
        string longestPalindrome(string s) {
            string longest_palindrome = "";
            for (int i = 0; i < s.size(); ++i) {
                // 寻找以s[i]为中心的奇数长度回文串
                string s1 = findPalindrome(s, i, i);
                string s2 = findPalindrome(s, i, i + 1);
                if (s1.size() > longest_palindrome.size()) longest_palindrome = s1;
                if (s2.size() > longest_palindrome.size()) longest_palindrome = s2;
            }
            return longest_palindrome;
        }
    };