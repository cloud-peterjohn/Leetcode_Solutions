// https://leetcode.com/problems/valid-arrangement-of-pairs/

class Solution
{
private:
    void traverse(unordered_map<int, vector<int>> &graph, vector<int> &results, int node)
    {
        while (!graph[node].empty())
        {
            int neigh = graph[node][0];
            // 删除边，避免无限循环遍历
            graph[node].erase(graph[node].begin());
            traverse(graph, results, neigh);
        }
        results.push_back(node);
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        // 有向图的欧拉路径：找出起点
        unordered_map<int, int> in_degree, out_degree;
        unordered_set<int> nodes; // 记录所有结点，避免遗漏只有入度/只有出度的结点
        for (const auto &p : pairs)
        {
            out_degree[p[0]]++;
            in_degree[p[1]]++;
            nodes.insert(p[0]);
            nodes.insert(p[1]);
        }
        // 由于题目声明一定存在欧拉路径，故无需判断
        // 如果存在两个结点出入度不相等，出度=入度+1的结点就是起始点
        int start_node = -1;
        for (const auto &node_number : nodes)
        {
            int input_degree = in_degree[node_number];
            int output_degree = out_degree[node_number];
            if (output_degree == input_degree + 1)
            {
                start_node = node_number;
            }
        }
        if (start_node == -1)
        {
            // 所有结点出度==入度，任选一个作为起始节点即可
            start_node = pairs[0][0];
        }

        // 转换为邻接表
        unordered_map<int, vector<int>> graph;
        for (const auto &p : pairs)
        {
            graph[p[0]].push_back(p[1]);
        }

        // 后序遍历
        vector<int> results;
        traverse(graph, results, start_node);
        reverse(results.begin(), results.end());

        // 将[11,9,4,5,1]转变为[[11,9],[9,4],[4,5],[5,1]]
        vector<vector<int>> arrangements;
        for (int i = 0; i < results.size() - 1; i++)
        {
            arrangements.push_back(vector<int>{results[i], results[i + 1]});
        }
        return arrangements;
    }
};