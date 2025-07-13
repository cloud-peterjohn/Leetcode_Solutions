// https://leetcode.com/problems/non-overlapping-intervals/

class Solution
{
private:
    struct Compare
    {
        bool operator()(vector<int> &inter1, vector<int> &inter2)
        {
            return inter1[1] < inter2[1];
        }
    };

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int m = intervals.size();
        int non_overlap_count = 1;
        // 排序
        sort(intervals.begin(), intervals.end(), Compare());
        // 计算有几个不相交区间
        int end_i = intervals[0][1];
        for (int i = 0; i < m; ++i)
        {
            int start_i = intervals[i][0];
            if (start_i >= end_i)
            {
                // 更新区间x，更新其end_i
                end_i = intervals[i][1];
                non_overlap_count++;
            }
        }
        return intervals.size() - non_overlap_count;
    }
};