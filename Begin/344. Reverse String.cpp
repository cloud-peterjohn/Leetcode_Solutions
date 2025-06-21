// https://leetcode.com/problems/reverse-string/description/

// Using Standard Library (STL)
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};

// Using Double Pointers
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};