// https://leetcode.com/problems/permutation-in-string/description/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.size() < s1.size())
            return false; // 模式串比目标串还长，一定无法匹配

        int left = 0; // 固定的窗口大小
        int length = s1.size();
        unordered_map<char, int> dict_s1, dict_s2;
        for (char ch : s1)
            ++dict_s1[ch];
        for (int i = 0; i < length; ++i)
            ++dict_s2[s2[i]]; // 预先放入length个字符

        while (left <= s2.size() - length)
        {
            // 判断是否满足要求
            bool is_permutations = true;
            for (auto p : dict_s1)
            {
                if (dict_s2[p.first] != p.second)
                {
                    is_permutations = false;
                    break;
                }
            }
            if (is_permutations)
                return true;

            // 窗口右移
            --dict_s2[s2[left]];
            ++left;
            ++dict_s2[s2[left + length - 1]];
        }
        return false;
    }
};