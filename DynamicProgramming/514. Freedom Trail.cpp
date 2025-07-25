// https://leetcode.com/problems/freedom-trail/

class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        // dp_table[i][j]表示当罗盘指针指向ring[i]时，再输入key[j:]所需要的旋转次数
        int m = ring.size(), n = key.size();
        vector<vector<int>> dp_table(m, vector<int>(n + 1, INT_MAX));
        unordered_map<char, vector<int>> map; // 字符ch所在的所有索引
        for (int i = 0; i < ring.size(); ++i)
        {
            map[ring[i]].push_back(i);
        }
        // base case
        for (int i = 0; i < m; ++i)
        {
            dp_table[i][n] = 0;
        }
        // DP
        for (int j = n - 1; j >= 0; --j)
        {
            for (int i = 0; i < m; ++i)
            {
                // 状态转换
                for (const auto idx : map[key[j]])
                {
                    int steps = min(abs(idx - i), m - abs(idx - i)); // 顺时针和逆时针
                    dp_table[i][j] = min(dp_table[idx][j + 1] + steps, dp_table[i][j]);
                }
            }
        }
        return dp_table[0][0] + n;
    }
};