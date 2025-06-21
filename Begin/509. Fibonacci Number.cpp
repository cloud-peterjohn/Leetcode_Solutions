// https://leetcode.com/problems/fibonacci-number/description/

// 递归
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

// 迭代
class Solution
{
public:
    int fib(int n)
    {
        vector<int> dp_table(n + 1, -1);
        for (int i = 0; i <= n; ++i)
        {
            if (i <= 1)
                dp_table[i] = i;
            else
                dp_table[i] = dp_table[i - 1] + dp_table[i - 2];
        }
        return dp_table[n];
    }
};

// 进一步，只存储之前的两个状态
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    // 分别代表 dp[i - 1] 和 dp[i - 2]
    int dp_i_1 = 1, dp_i_2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int dp_i = dp_i_1 + dp_i_2;
        dp_i_2 = dp_i_1;
        dp_i_1 = dp_i;
    }
    return dp_i_1;
}
