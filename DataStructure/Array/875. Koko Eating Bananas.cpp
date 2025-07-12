// https://leetcode.com/problems/koko-eating-bananas/

class Solution
{
private:
    long f(int speed, const vector<int> &piles)
    {
        // 单调递减函数：对于进食速度speed，返回进食需要的time小时
        long time = 0;
        for (const auto pile : piles)
        {
            time += long(pile / speed);
            if (pile % speed != 0)
                time++;
        }
        return time;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // 二分搜索自变量进食速度的定义域[left, right]
        int left = 1;
        int right = -1;
        for (const auto pile : piles)
            right = max(right, pile);
        // 二分搜索
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (f(mid, piles) == h)
            {
                right = mid - 1;
            }
            else if (f(mid, piles) < h)
            { // 单减函数：值太小反而应该左移x
                right = mid - 1;
            }
            else if (f(mid, piles) > h)
            {
                left = mid + 1;
            }
        }
        return left;
    }
};