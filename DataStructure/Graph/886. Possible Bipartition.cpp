// https://leetcode.com/problems/possible-bipartition/

class Solution
{
private:
    bool is_bipartition = true;
    void traverse(const vector<vector<int>> &graph, vector<bool> &visited, vector<int> &color, int node)
    {
        visited[node] = true;
        for (const auto neigh : graph[node])
        {
            if (visited[neigh] == false)
            {
                // 未访问过，递归
                if (color[node] == 1)
                    color[neigh] = -1;
                else
                    color[neigh] = 1;
                traverse(graph, visited, color, neigh);
            }
            else
            {
                // 已访问过，如邻居结点颜色相同，则不是二分图
                if (color[node] == color[neigh])
                {
                    this->is_bipartition = false;
                    return;
                }
            }
        }
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        // 转换为邻接表
        vector<vector<int>> graph(n);
        for (const auto dislike : dislikes)
        {
            int node_i = dislike[0] - 1, node_j = dislike[1] - 1;
            graph[node_i].push_back(node_j);
            graph[node_j].push_back(node_i);
        }
        // 判断二分图
        vector<bool> visited(n, false);
        vector<int> color(n, 1);
        bool isPossibleBipartition = true;
        for (int i = 0; i < graph.size(); ++i)
        {
            traverse(graph, visited, color, i);
            if (is_bipartition == false)
            {
                isPossibleBipartition = false;
                break;
            }
        }
        return isPossibleBipartition;
    }
};