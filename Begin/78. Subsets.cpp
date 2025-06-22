// https://leetcode.com/problems/subsets/

class Solution
{
private:
    vector<vector<int>> subset{{}}; // 初始时包含一个空集[[],...]
    void backtrack(const vector<int> &nums, int nums_begin_idx, vector<int> &visited, vector<int> &track)
    {
        for (int i = nums_begin_idx; i < nums.size(); ++i)
        {
            // 回溯算法
            visited.push_back(nums[i]);
            track.push_back(nums[i]);
            this->subset.push_back(track);          // 保存结果子集
            backtrack(nums, i + 1, visited, track); // i+1确保子集不重复
            visited.pop_back();
            track.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> visited;
        vector<int> track;
        backtrack(nums, 0, visited, track);
        return this->subset;
    }
};