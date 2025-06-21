// https://leetcode.com/problems/permutations/description/

class Solution
{
private:
    vector<vector<int>> permutations;
    void backtrack(const vector<int> &nums, vector<int> &track, vector<bool> &used)
    {
        // 路径中包含所有数字，已经形成一种全排列
        if (track.size() == nums.size())
        {
            this->permutations.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i])
                continue; // 已经存在于路径中
            // 将数字加入路径
            track.push_back(nums[i]);
            used[i] = true;
            // 进入下一层
            backtrack(nums, track, used);
            // 从当前层退出
            track.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> track;
        vector<bool> used(nums.size(), false);
        backtrack(nums, track, used);
        return this->permutations;
    }
};