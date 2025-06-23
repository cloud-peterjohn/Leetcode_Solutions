// https://leetcode.com/problems/subsets-ii/description/

class Solution
{
private:
    vector<vector<int>> subsets{{}};
    void backtrack(const vector<int> &nums, vector<int> &track, int begin_index)
    {
        for (int i = begin_index; i < nums.size(); ++i)
        {
            if ((i > begin_index) && (nums[i] == nums[i - 1]))
                continue; // 遇到重复的数字
            track.push_back(nums[i]);
            subsets.push_back(track);
            backtrack(nums, track, i + 1);
            track.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), less<int>()); // 降序的greater<int>()也可以
        vector<int> track;
        backtrack(nums, track, 0);
        return subsets;
    }
};