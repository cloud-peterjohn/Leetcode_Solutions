// https://leetcode.com/problems/time-needed-to-buy-tickets

class Solution
{
public:
    int _find_min(const vector<int> &tickets)
    {
        int min_num = 99999;
        for (const auto &num : tickets)
        {
            if (num == 0)
            {
                continue;
            }
            else
            {
                if (num < min_num)
                {
                    min_num = num;
                }
            }
        }
        return min_num;
    }
    int _buy(vector<int> &tickets, const int &buy_num, const int &k)
    {
        int count = 0;
        for (auto &num : tickets)
        {
            if (num == 0)
            {
                continue;
            }
            else if (tickets[k] == 0)
            {
                num = num - buy_num;
                count = count + (buy_num - 1);
            }
            else
            {
                num = num - buy_num;
                count = count + buy_num;
            }
        }
        return count;
    }
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int current_time = 0;
        while (tickets[k] != 0)
        {
            int min_num = _find_min(tickets);
            int count = _buy(tickets, min_num, k);
            current_time += count;
        }
        return current_time;
    }
};