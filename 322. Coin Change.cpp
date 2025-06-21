// https://leetcode.com/problems/coin-change/description/

// 暴力搜索
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // base case
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        // 找零一个硬币
        int min_coin = 999;
        for (int coin : coins)
        {
            int sub_prob_cnt = coinChange(coins, amount - coin);
            if (sub_prob_cnt == -1)
                continue;
            min_coin = min(min_coin, sub_prob_cnt + 1);
        }

        // 找不开
        if (min_coin == 999)
            return -1;
        return min_coin;
    }
};

// 使用DP Table避免重复计算
class Solution {
private:
    int coin_change(vector<int>& coins, int amount, vector<int> dp_table) {
        // base
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        
        // query table
        if (dp_table[amount] != -2) return dp_table[amount];

        int min_nums = 99999;
        for (const int coin : coins) {
            int nums = coin_change(coins, amount - coin, dp_table);
            if (nums == -1) continue;    // 无法找开
            if (nums + 1 < min_nums) min_nums = nums + 1;
        }

        // 无法找开
        if (min_nums == 99999) return -1;
        dp_table[amount] = min_nums;
        return min_nums;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp_table(amount + 1, -2);
        return coin_change(coins, amount, dp_table);
    }
};

// 迭代
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp_table(amount + 1);
        dp_table[0] = 0;
        for (int amt = 1; amt <= amount; ++amt)
        {
            int min_cnt = 99999;
            for (const int coin : coins)
            {
                if (amt - coin < 0)
                    continue; // 为负，不可行
                int cnt = dp_table[amt - coin];
                if (cnt == -1)
                    continue; // 找不开
                if (cnt + 1 < min_cnt)
                    min_cnt = cnt + 1;
            }
            if (min_cnt == 99999)
                dp_table[amt] = -1; // 找不开
            else
                dp_table[amt] = min_cnt;
        }
        return dp_table[amount];
    }
};