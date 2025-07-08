// https://leetcode.com/problems/range-addition-ii/

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        if (ops.size() == 0)
            return m * n;
        int a_min = 999999, b_min = 999999;
        for (auto line : ops)
        {
            int a = line[0], b = line[1];
            a_min = min(a_min, a);
            b_min = min(b_min, b);
        }
        return a_min * b_min;
    }
};