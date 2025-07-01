// https://leetcode.com/problems/ugly-number-ii/

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;
        vector<int> ugly_num{1};
        int idx2 = 0, idx3 = 0, idx5 = 0;
        while (ugly_num.size() < n)
        {
            // 选取一个最小的丑数
            int ugly_number = min(min(2 * ugly_num[idx2], 3 * ugly_num[idx3]), 5 * ugly_num[idx5]);
            if (ugly_number == 2 * ugly_num[idx2])
                ++idx2;
            if (ugly_number == 3 * ugly_num[idx3])
                ++idx3;
            if (ugly_number == 5 * ugly_num[idx5])
                ++idx5;
            ugly_num.push_back(ugly_number);
        }
        return ugly_num[n - 1];
    }
};