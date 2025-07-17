// https://leetcode.com/problems/course-schedule-ii/

class Solution
{
private:
    bool has_cycle = false;
    vector<int> topology;
    void traverse(const vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &on_path, int node)
    {
        // DFS判断是否成环
        if (on_path[node])
        { // on_path必须先于visited判断
            this->has_cycle = true;
            return;
        }
        if (visited[node])
            return;
        visited[node] = true;
        on_path[node] = true; // 回溯
        for (auto neigh : graph[node])
        {
            traverse(graph, visited, on_path, neigh);
        }
        topology.push_back(node);
        on_path[node] = false;
    }
    bool is_cycle(const vector<vector<int>> &graph)
    {
        // 可能不连通，所以需要遍历的执行
        vector<bool> visited(graph.size());
        vector<bool> on_path(graph.size()); // 每次循环都共用，postorder只存每个节点第一次递归完成后的后序结果
        for (int i = 0; i < graph.size(); ++i)
        {
            this->has_cycle = false;
            traverse(graph, visited, on_path, i);
            if (this->has_cycle)
                return true;
        }
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // 转化为邻接表
        vector<vector<int>> graph(numCourses);
        for (const auto prereq : prerequisites)
        {
            graph[prereq[1]].push_back(prereq[0]);
        }
        // 判断是否成环，同时记录拓扑排序
        if (is_cycle(graph))
            return vector<int>{};
        // 反转后序遍历结果
        reverse(this->topology.begin(), this->topology.end());
        return this->topology;
    }
};