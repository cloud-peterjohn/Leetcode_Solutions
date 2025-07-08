// https://leetcode.com/problems/repeated-dna-sequences/

// NAIVE解法
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.size() < 10)
            return vector<string>{};
        int idx = 0;
        unordered_set<string> set;
        vector<string> repeated_sequences;
        while (idx <= s.size() - 10)
        {
            string sub = s.substr(idx++, 10);
            if (set.find(sub) == set.end())
            {
                set.insert(sub);
            }
            else if (find(repeated_sequences.begin(), repeated_sequences.end(), sub) == repeated_sequences.end())
            {
                repeated_sequences.push_back(sub);
            }
        }
        return repeated_sequences;
    }
};

// 滑动哈希解法
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        // 将字符串哈希为数字
        vector<int> nums;
        for (const auto ch : s)
        {
            if (ch == 'A')
                nums.push_back(0);
            else if (ch == 'T')
                nums.push_back(1);
            else if (ch == 'G')
                nums.push_back(2);
            else if (ch == 'C')
                nums.push_back(3);
        }
        int L = 10; // 10位数
        int R = 4;  // 4种字符 --> 4进制
        // 滑动窗口
        unordered_set<int> seen_substr;
        unordered_set<string> results;
        int left = 0, right = 0;
        int window_hash = 0;
        while (right < nums.size())
        {
            // 窗口扩大
            window_hash = window_hash * R + nums[right++];
            // 当字串长度达到10
            if (right - left == L)
            {
                if (seen_substr.find(window_hash) == seen_substr.end())
                {
                    seen_substr.insert(window_hash);
                }
                else
                {
                    // 找到了重复子串
                    string sub_string = s.substr(left, L);
                    if (results.find(sub_string) == results.end())
                    {
                        results.insert(sub_string);
                    }
                }
                // 窗口缩小
                window_hash = window_hash - nums[left++] * (pow(R, L - 1));
            }
        }
        return vector<string>(results.begin(), results.end()); // set --> vector
    }
};