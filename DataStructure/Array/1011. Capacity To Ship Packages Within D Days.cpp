// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution
{
private:
    int f(int ship_capacity, const vector<int> &weights)
    {
        // 单减函数：对于自变量ship_capacity，返回最少的搬运天数（趟数）
        if (weights.size() == 0 || (weights.size() == 1 && weights[0] == 0))
            return 0;
        int days = 1;
        int idx = 0;
        int sum = 0;
        while (idx < weights.size())
        {
            sum += weights[idx];
            if (sum > ship_capacity)
            {
                // if (weights[idx] > ship_capacity) return -1;
                sum = weights[idx];
                days++;
            }
            idx++;
        }
        return days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        // 自变量取值范围[left, right]
        int left = 0;
        int right = 0;
        for (const auto weight : weights)
        {
            left = max(left, weight);
            right += weight;
        }
        // 二分搜索
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int curr_days = f(mid, weights);
            if (curr_days == days)
            {
                right = mid - 1;
            }
            // 由于f(x)是单减函数，所以需要和普通的二分搜索反过来
            else if (curr_days > days)
            {
                left = mid + 1;
            }
            else if (curr_days < days)
            {
                right = mid - 1;
            }
        }
        return left;
    }
};