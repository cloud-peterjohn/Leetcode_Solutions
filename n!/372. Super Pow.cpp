// https://leetcode.com/problems/super-pow/

class Solution
{
    int mypow(int a, int k)
    {
        a = a % 1337;
        int res = 1;
        for (int i = 0; i < k; i++)
        {
            res = (a * res) % 1337;
        }
        return res;
    }

public:
    int superPow(int a, vector<int> &b)
    {
        // 递归的base case
        if (b.empty())
            return 1;
        // 取出最后一个元素并删除
        int last_num = b[b.size() - 1];
        b.erase(b.end() - 1);
        // 分别求解
        int pow1 = mypow(a, last_num);
        int pow2 = mypow(superPow(a, b), 10);
        return (pow1 * pow2) % 1337;
    }
};