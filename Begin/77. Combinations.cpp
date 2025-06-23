// https://leetcode.com/problems/combinations/description/

class Solution
{
private:
    vector<vector<int>> combinations;
    void backtrack(int begin_num, int end_num, int total_length, vector<int> &track)
    {
        for (int i = begin_num; i <= end_num; ++i)
        {
            track.push_back(i);
            if (track.size() == total_length)
                combinations.push_back(track);
            else
                backtrack(i + 1, end_num, total_length, track);
            track.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> track;
        backtrack(1, n, k, track);
        return combinations;
    }
};