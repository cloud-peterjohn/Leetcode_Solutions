// https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int result = 0;
        for (int num = n; num > 0; num /= 5)
        {
            result += num / 5;
        }
        return result;
    }
};