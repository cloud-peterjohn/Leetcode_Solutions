// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution
{
public:
    vector<int> path;
    vector<vector<int>> all_path;
    unordered_set<int> on_path;
    void findAllPath(const vector<vector<int>> &graph, int curr, int src, int dest)
    {
        if (on_path.find(curr) != on_path.end())
            return;
        // 访问当前结点
        on_path.insert(curr);
        path.push_back(curr);
        // 找到一条路径
        if (curr == dest)
            all_path.push_back(path);
        // 递归
        for (auto node : graph[curr])
        {
            findAllPath(graph, node, src, dest);
        }
        // 离开当前结点
        path.pop_back();
        on_path.erase(curr);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        findAllPath(graph, 0, 0, graph.size() - 1);
        return all_path;
    }
};