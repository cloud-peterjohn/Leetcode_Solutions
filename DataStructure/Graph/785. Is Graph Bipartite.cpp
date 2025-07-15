// https://leetcode.com/problems/is-graph-bipartite/

class Solution
{
private:
    bool is_bipartite = true;
    void traverse(const vector<vector<int>> &graph, vector<bool> &visited, vector<int> &color, int node)
    {
        visited[node] = true;
        int node_color = color[node];
        for (const auto neighbour : graph[node])
        {
            if (visited[neighbour] == false)
            { // 避免无限递归
                // 赋予不同的颜色
                if (node_color == 1)
                    color[neighbour] = -1;
                else
                    color[neighbour] = 1;
                traverse(graph, visited, color, neighbour);
            }
            else
            {
                // 相邻结点颜色相同，不是二分图
                if (node_color == color[neighbour])
                {
                    is_bipartite = false;
                    return;
                }
            }
        }
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<bool> visited(graph.size(), false);
        vector<int> color(graph.size(), 1);
        // 图不一定是联通的，可能存在多个子图，所以把每个节点都作为起点进行一次遍历
        bool is_bipartite_all = true;
        for (int i = 0; i < graph.size(); ++i)
        {
            traverse(graph, visited, color, i);
            if (is_bipartite == false)
                is_bipartite_all = false;
        }
        return is_bipartite_all;
    }
};
