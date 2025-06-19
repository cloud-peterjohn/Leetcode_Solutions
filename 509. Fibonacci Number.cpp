// https://leetcode.com/problems/fibonacci-number/description/

class Solution
{
    int fibonacci(int n, vector<int> &dp_table)
    {
        // 检查是否已经计算过
        if (dp_table[n] != -1)
            return dp_table[n];

        if (n <= 1)
        {
            dp_table[n] = n;
            return n;
        }

        int fib_val = fibonacci(n - 1, dp_table) + fibonacci(n - 2, dp_table);
        // 保存计算的值
        dp_table[n] = fib_val;
        return fib_val;
    }

public:
    int fib(int n)
    {
        vector<int> dp_table(n + 1, -1);
        return fibonacci(n, dp_table);
    }
};