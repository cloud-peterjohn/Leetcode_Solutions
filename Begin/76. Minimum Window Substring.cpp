// https://leetcode.com/problems/minimum-window-substring/description/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // 计算t中各个字符出现次数
        unordered_map<char, int> t_dict;
        for (auto ch : t)
            t_dict[ch] += 1;

        // 初始化
        int left = 0, right = 0;              // 初始化滑动窗口（左闭右开）
        unordered_map<char, int> window_dict; // 记录窗口的字符及其出现次数
        pair<int, int> shortest_substr(-1, -1);
        int shortest_substr_len = 99999;

        while (right <= s.size())
        {
            // 窗口扩大
            if (right < s.size())
                ++window_dict[s[right]];
            ++right;
            // 判断窗口是否包含了t中每一个字符
            bool is_contain_all = true;
            for (const auto p : t_dict)
            {
                if (window_dict[p.first] < p.second)
                {
                    is_contain_all = false;
                    break;
                }
            }

            // 如果包含全部字符，则窗口缩小
            while ((is_contain_all) && (left < right))
            {
                // 记录子串及其长度
                if ((right - left) < shortest_substr_len)
                {
                    shortest_substr_len = right - left;
                    shortest_substr = pair<int, int>(left, shortest_substr_len);
                }
                // 窗口减小
                --window_dict[s[left]];
                ++left;
                // 判断窗口是否包含了t中每一个字符
                for (const auto p : t_dict)
                {
                    if (window_dict[p.first] < p.second)
                    {
                        is_contain_all = false;
                        break;
                    }
                }
            }
        }
        if ((shortest_substr.first != -1) && (shortest_substr.second != -1))
            return s.substr(shortest_substr.first, shortest_substr.second);
        else
            return "";
    }
};