// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

class Solution
{
private:
    vector<vector<int>> results;
    struct Compare
    {
        bool operator()(const vector<int> &nums1, const vector<int> &nums2)
        {
            return nums1[0] + nums1[1] > nums2[0] + nums2[1];
        }
    };

public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for (int i = 0; i < nums1.size(); ++i)
        {
            pq.push(vector<int>{nums1[i], nums2[0], 0});
        }
        while (!pq.empty())
        {
            vector<int> pairs = pq.top();
            pq.pop();

            results.push_back(vector<int>{pairs[0], pairs[1]});
            if (results.size() == k)
                return results;

            if (pairs[2] + 1 < nums2.size())
                pq.push(vector<int>{pairs[0], nums2[pairs[2] + 1], pairs[2] + 1});
        }
        return results;
    }
};