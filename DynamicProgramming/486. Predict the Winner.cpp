// https://leetcode.com/problems/predict-the-winner/

class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        // dp_table[i][j]表示对`nums[i...j]，先手和后手能获得的最高分数
        vector<vector<pair<int, int>>> dp_table(n, vector<pair<int, int>>(n, pair<int, int>{0, 0}));

        // base case: i == j
        for (int i = 0; i < n; ++i)
        {
            dp_table[i][i].first = nums[i];
            dp_table[i][i].second = 0;
        }

        // DP
        for (int i = n - 2; i >= 0; --i)
        { // i逆向遍历，i最大为n-2（nums[n-2...n-1]）
            for (int j = i + 1; j < n; ++j)
            { // j > i
                // 选择最左边的数
                int left = nums[i] + dp_table[i + 1][j].second;
                // 选择最右边的数
                int right = nums[j] + dp_table[i][j - 1].second;
                // 更新先后手的最大得分
                dp_table[i][j].first = max(left, right);
                if (left >= right)
                    dp_table[i][j].second = dp_table[i + 1][j].first; // 当先手选择左
                else
                    dp_table[i][j].second = dp_table[i][j - 1].first; // 当先手选择右
            }
        }

        if (dp_table[0][n - 1].first >= dp_table[0][n - 1].second)
            return true;
        else
            return false;
    }
};