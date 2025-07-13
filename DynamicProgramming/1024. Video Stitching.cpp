// https://leetcode.com/problems/video-stitching/

class Solution
{
private:
    struct Compare
    {
        bool operator()(const vector<int> &clip1, const vector<int> &clip2)
        {
            if (clip1[0] == clip2[0])
                return clip1[1] > clip2[1];
            else
                return clip1[0] < clip2[0];
        }
    };

public:
    int videoStitching(vector<vector<int>> &clips, int time)
    {
        sort(clips.begin(), clips.end(), Compare());
        if (clips[0][0] != 0)
            return -1;         // 拼出[0..time]至少需要一个0开头的片段
        int min_num_clips = 0; // 所需片段的最小数目

        int i = 0;
        int curr_end = 0;
        while (i < clips.size() && curr_end < time)
        {
            // 在第res视频内贪心地选择下一个视频
            int next_end = curr_end;
            while (i < clips.size() && clips[i][0] <= curr_end)
            {
                // 有交集的视频区间中，贪心地选最长
                next_end = max(next_end, clips[i][1]);
                i++;
            }
            // 无法继续右移
            if (next_end == curr_end)
                return -1;
            // 找到了下一个视频
            curr_end = next_end;
            min_num_clips++;
        }
        if (curr_end >= time)
            return min_num_clips;
        else
            return -1;
    }
};