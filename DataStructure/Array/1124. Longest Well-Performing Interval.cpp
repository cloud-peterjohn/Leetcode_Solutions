// https://leetcode.com/problems/longest-well-performing-interval/

class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        // tiring记录为1，non-tiring记录为-1
        vector<int> prefix(hours.size() + 1, 0);
        for (int i = 0; i < hours.size(); ++i)
        {
            if (hours[i] > 8)
            {
                prefix[i + 1] = prefix[i] + 1;
            }
            else
            {
                prefix[i + 1] = prefix[i] - 1;
            }
        }
        unordered_map<int, int> map; // 前缀和的值第一次出现的位置
        map[0] = 0;
        int interval = 0;
        for (int i = 0; i < hours.size(); ++i)
        {
            // [0, i]区间内tiring天数更多
            if (prefix[i + 1] > 0)
            {
                interval = max(interval, i + 1);
            }
            // 查找值小于prefix[i + 1]的索引，只需找prefix[i + 1] - 1即可
            else if (map.find(prefix[i + 1] - 1) != map.end())
            {
                interval = max(interval, i + 1 - map[prefix[i + 1] - 1]);
            }
            // 如果prefix值首次出现，则存入map
            if (map.find(prefix[i + 1]) == map.end())
            {
                map[prefix[i + 1]] = i + 1;
            }
        }
        return interval;
    }
};