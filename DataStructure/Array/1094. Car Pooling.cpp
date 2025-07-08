// https://leetcode.com/problems/car-pooling/

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> passengers_diff(1001, 0); // 车行驶到每个站点的乘客数量
        for (const auto trip : trips)
        {
            int num_passengers = trip[0], from = trip[1], to = trip[2];
            passengers_diff[from] += num_passengers;       // from站乘客上车
            passengers_diff[to - 1 + 1] -= num_passengers; // to - 1站已经下车
        }

        vector<int> passengers(1001, 0);
        passengers[0] = passengers_diff[0];
        if (passengers[0] > capacity)
            return false;
        for (int i = 1; i < passengers_diff.size(); ++i)
        {
            passengers[i] = passengers[i - 1] + passengers_diff[i];
            if (passengers[i] > capacity)
                return false;
        }
        return true;
    }
};