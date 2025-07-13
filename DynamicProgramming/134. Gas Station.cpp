// https://leetcode.com/problems/gas-station/

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int sum = 0, min_sum = 999999, min_sum_idx = -1;
        for (int i = 0; i < gas.size(); ++i)
        {
            // 离开第i个站点后，油量剩余sum
            sum += (gas[i] - cost[i]);
            if (sum < min_sum)
            {
                min_sum_idx = i;
                min_sum = sum;
            }
        }
        // sum(gas[...]) < sum(cost[...])
        if (sum < 0)
            return -1;
        // 离开 min_sum_idx站点后油量最低，即位于min_sum_idx + 1时油量最低
        else
            return (min_sum_idx + 1) % gas.size();
    }
};