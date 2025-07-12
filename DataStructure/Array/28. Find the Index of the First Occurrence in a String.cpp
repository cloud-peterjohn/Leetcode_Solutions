// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int Q = 598167; // 选择一个取模的除数
        int R = 256;    // ASCII码
        int L = needle.size();
        // 哈希模式串
        int target_hash = 0;
        for (const auto ch : needle)
        {
            target_hash = ((target_hash * R) % Q + int(ch)) % Q;
        }
        // 预先计算pow(R, L-1)，避免重复多次计算
        int pow_R_L = 1;
        for (int i = 0; i < L - 1; ++i)
        {
            pow_R_L = (pow_R_L * R) % Q;
        }
        // 滑动窗口
        int window_hash = 0;
        int left = 0, right = 0;
        while (right < haystack.size())
        {
            // 扩大窗口
            window_hash = ((window_hash * R) % Q + int(haystack[right++])) % Q;
            if (right - left == L)
            {
                // 如果哈希值相同
                if (window_hash == target_hash)
                {
                    // 取子串判断是否真的相同，避免哈希冲突
                    if (haystack.substr(left, L) == needle)
                    {
                        return left;
                    }
                }
                // 缩小左边界，使窗口一直维持大小L
                window_hash = (window_hash - (haystack[left++] * pow_R_L) % Q + Q) % Q;
            }
        }
        return -1;
    }
};