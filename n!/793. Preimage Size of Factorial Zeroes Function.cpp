// https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/

#include <bits/stdc++.h>

class Solution
{
private:
    long trailing_zeroes(long n)
    {
        // 计算n!有多少个后导0
        long cnt = 0;
        for (long num = n; num > 0; num /= 5)
        {
            cnt += num / 5;
        }
        return cnt;
    }
    bool binary_search(long left, long right, long target)
    {
        // 二分搜索
        if (left > right)
            return false;
        long mid = left + (right - left) / 2;
        long zeros = trailing_zeroes(mid);
        if (zeros == target)
        {
            return true;
        }
        else if (zeros > target)
        {
            return binary_search(left, mid - 1, target);
        }
        else
        {
            return binary_search(mid + 1, right, target);
        }
    }

public:
    int preimageSizeFZF(int k)
    {
        long left = 0, right = LONG_MAX;
        bool has_number = binary_search(left, right, k);
        if (has_number)
            return 5;
        else
            return 0;
    }
};