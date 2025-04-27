// https://leetcode.com/problems/valid-parentheses

class Solution
{
public:
    bool isMatch(char ch1, char ch2)
    {
        if (ch1 == '(' and ch2 == ')')
            return true;
        if (ch1 == '[' and ch2 == ']')
            return true;
        if (ch1 == '{' and ch2 == '}')
            return true;
        return false;
    }
    bool isValid(string s)
    {
        stack<int> st1;
        for (const auto &ch : s)
        {
            if (ch == '(' or ch == '{' or ch == '[')
            {
                st1.push(ch);
            }
            else
            {
                if (not st1.empty() and (isMatch(st1.top(), ch)))
                {
                    st1.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (st1.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};