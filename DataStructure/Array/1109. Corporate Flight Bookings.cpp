// https://leetcode.com/problems/corporate-flight-bookings/

class Solution
{
private:
    void modify_diff(vector<int> &diff, int left_idx, int right_idx, int seat_num)
    {
        // [left_idx, right_idx]区间内加seat_num
        diff[left_idx] += seat_num;
        if (right_idx + 1 < diff.size())
            diff[right_idx + 1] -= seat_num;
    }

public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        // 创建差分数组
        vector<int> diff(n, 0); // 初始时所有航班预定数量均为0
        // 修改diff
        for (auto reserve : bookings)
        {
            modify_diff(diff, reserve[0] - 1, reserve[1] - 1, reserve[2]);
        }
        // 还原数组
        vector<int> answer(n, 0);
        answer[0] = diff[0];
        for (int i = 1; i < n; ++i)
        {
            answer[i] = answer[i - 1] + diff[i];
        }
        return answer;
    }
};