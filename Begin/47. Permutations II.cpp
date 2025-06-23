// https://leetcode.com/problems/permutations-ii/

class Solution
{
private:
    vector<vector<int>> permutations;
    void backtrack(const vector<int> &nums, vector<int> &track, vector<bool> &visited)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            // 避免重复取同一个元素
            if (visited[i])
                continue;

            // 避免因重复元素值造成排列重复
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;

            track.push_back(nums[i]);
            visited[i] = true;

            // 结束条件
            if (track.size() == nums.size())
                permutations.push_back(track);

            // 回溯
            backtrack(nums, track, visited);
            track.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), less<int>());
        vector<int> track;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, track, visited);
        return this->permutations;
    }
};