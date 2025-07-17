// https://leetcode.com/problems/course-schedule/

class Solution
{
private:
    bool has_cycle = false;
    void traverse(const vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &on_path, int node)
    {
        if (on_path[node] == true)
        { // 出现了环（必须最先判断）
            this->has_cycle = true;
            return;
        }
        if (visited[node] == true)
            return; // 遍历过的结点，直接跳过
        // 递归
        visited[node] = true;
        on_path[node] = true;
        for (const auto neigh : graph[node])
        {
            traverse(graph, visited, on_path, neigh);
        }
        on_path[node] = false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // 构建图的邻接表
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            int from_i = prerequisites[i][0], to_i = prerequisites[i][1];
            graph[from_i].push_back(to_i);
        }
        // DFS
        vector<bool> visited(numCourses, false); // 已访问过的结点
        vector<bool> on_path(numCourses, false); // 在递归堆栈上的结点
        for (int i = 0; i < numCourses; ++i)
        { // 避免图不连通
            traverse(graph, visited, on_path, i);
            if (has_cycle == true)
                return false; // 有环时返回false
        }
        return true; // 无环时返回true
    }
};