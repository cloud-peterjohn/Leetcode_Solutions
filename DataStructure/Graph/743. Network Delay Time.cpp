// https://leetcode.com/problems/network-delay-time/

class Solution
{
private:
    struct State
    {
        int node;
        int distance;
        State(int node, int distance) : node(node), distance(distance) {}
    };
    struct Compare
    {
        bool operator()(const State &s1, const State &s2)
        {
            return s1.distance > s2.distance;
        }
    };
    vector<int> dijkstra(const vector<vector<int>> &graph, const vector<vector<int>> &edge_weights, int src)
    {
        vector<int> dist(graph.size(), -1);
        priority_queue<State, vector<State>, Compare> pq;
        pq.push(State(src, 0));
        while (!pq.empty())
        {
            State s = pq.top();
            pq.pop();
            if (dist[s.node] != -1)
            {
                continue;
            }
            else
            {
                dist[s.node] = s.distance;
            }
            for (const auto neigh : graph[s.node])
            {
                int neigh_distance = s.distance + edge_weights[s.node][neigh];
                if (dist[neigh] != -1)
                {
                    continue;
                }
                else
                {
                    pq.push(State(neigh, neigh_distance));
                }
            }
        }
        return dist;
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // 构建邻接表
        vector<vector<int>> graph(n);
        vector<vector<int>> edge_weights(n, vector<int>(n, 999999));
        for (const auto time : times)
        {
            int from_i = time[0] - 1, to_i = time[1] - 1;
            graph[from_i].push_back(to_i);
            edge_weights[from_i][to_i] = time[2];
        }
        // 最短路径
        vector<int> min_dis = dijkstra(graph, edge_weights, k - 1);
        int delay_time = 0;
        for (const auto time : min_dis)
        {
            delay_time = max(delay_time, time);
        }
        if (delay_time == 0)
            return -1;
        else
            return delay_time;
    }
};