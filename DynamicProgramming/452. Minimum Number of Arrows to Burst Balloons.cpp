// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

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
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), Compare());
        int non_overlap = 1;
        int end = points[0][1];
        for (int i = 0; i < points.size(); ++i)
        {
            int begin_i = points[i][0], end_i = points[i][1];
            if (begin_i > end)
            {
                end = end_i;
                non_overlap++;
            }
        }
        return non_overlap;
    }
};