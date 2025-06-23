// https://leetcode.com/problems/combination-sum/description/

class Solution
{
private:
    vector<vector<int>> combinations;
    void backtrack(const vector<int> &candidates, const int target, int begin_index, vector<int> &track, int &track_sum)
    {
        for (int i = begin_index; i < candidates.size(); ++i)
        {
            track.push_back(candidates[i]);
            track_sum += candidates[i];
            // 满足要求，记录结果
            if (track_sum == target)
                combinations.push_back(track);
            // 终止递归
            if (track_sum > target)
            {
                track.pop_back();
                track_sum -= candidates[i];
                continue;
            }
            // 回溯
            backtrack(candidates, target, i, track, track_sum);
            track.pop_back();
            track_sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> track;
        int track_sum = 0;
        backtrack(candidates, target, 0, track, track_sum);
        return this->combinations;
    }
};