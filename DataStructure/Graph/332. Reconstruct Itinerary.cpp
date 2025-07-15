// https://leetcode.com/problems/reconstruct-itinerary/

class Solution
{
private:
    void traverse(unordered_map<string, vector<string>> &graph, vector<string> &post_order, string node)
    {
        // 避免使用for (auto neigh : graph[node])，因为循环过程中也会修改边
        while (!graph[node].empty())
        {
            string neigh = graph[node][0];
            graph[node].erase(graph[node].begin()); // 删除首个元素
            traverse(graph, post_order, neigh);
        }
        post_order.push_back(node);
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // 转化为邻接表
        unordered_map<string, vector<string>> graph;
        for (int i = 0; i < tickets.size(); ++i)
        {
            string from_i = tickets[i][0], to_i = tickets[i][1];
            graph[from_i].push_back(to_i);
        }
        // 对每个出发地，对其所有目的地进行排序，以确保字典序
        for (auto &p : graph)
        {
            sort(p.second.begin(), p.second.end(), less<string>());
        }
        // Hierholzer算法寻找以JFK为起点的欧拉路径
        vector<string> post_order;
        traverse(graph, post_order, "JFK");
        reverse(post_order.begin(), post_order.end());
        return post_order;
    }
};