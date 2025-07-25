// https://leetcode.com/problems/path-with-minimum-effort/

class Solution
{
private:
    struct State
    {
        int i;
        int j;
        int effort; // 从起始点到[i, j]的最大高度差
        State(int i, int j, int effort) : i(i), j(j), effort(effort) {}
    };
    struct Compare
    {
        bool operator()(const State &s1, const State &s2)
        {
            return s1.effort > s2.effort;
        }
    };
    struct Graph
    {
        vector<vector<int>> heights;
        int rows;
        int cols;
        Graph(vector<vector<int>> &heights)
        {
            this->heights = heights;
            rows = heights.size();
            cols = heights[0].size();
        }
        vector<vector<int>> get_neighbours(int i, int j)
        {
            // 返回[i, j]的邻居节点
            vector<vector<int>> neighbours;
            if (i != 0)
                neighbours.push_back(vector<int>{i - 1, j});
            if (i != rows - 1)
                neighbours.push_back(vector<int>{i + 1, j});
            if (j != 0)
                neighbours.push_back(vector<int>{i, j - 1});
            if (j != cols - 1)
                neighbours.push_back(vector<int>{i, j + 1});
            return neighbours;
        }
        int get_edge_weight(int src_i, int src_j, int dest_i, int dest_j)
        {
            // 返回从src到dest的height之差的绝对值
            if (heights[dest_i][dest_j] - heights[src_i][src_j] >= 0)
            {
                return heights[dest_i][dest_j] - heights[src_i][src_j];
            }
            else
            {
                return heights[src_i][src_j] - heights[dest_i][dest_j];
            }
        }
    };
    int dijkstra(Graph &graph, int src_i, int src_j, int dest_i, int dest_j)
    {
        vector<vector<int>> dist(graph.rows, vector<int>(graph.cols, -1)); // 存储从起始点出发至点[i, j]的最大高度差
        priority_queue<State, vector<State>, Compare> pq;
        pq.push(State(0, 0, 0));
        // 寻找最大高度差最小的路径
        while (!pq.empty())
        {
            State s = pq.top();
            pq.pop();
            // 到达目标节点，立刻返回
            if (s.i == dest_i && s.j == dest_j)
            {
                return s.effort;
            }
            if (dist[s.i][s.j] != -1)
            {
                continue;
            }
            dist[s.i][s.j] = s.effort;
            for (auto neigh : graph.get_neighbours(s.i, s.j))
            {
                int neigh_i = neigh[0], neigh_j = neigh[1];
                if (dist[neigh_i][neigh_j] != -1)
                {
                    continue;
                }
                int neigh_effort = max(s.effort, graph.get_edge_weight(s.i, s.j, neigh_i, neigh_j));
                pq.push(State(neigh_i, neigh_j, neigh_effort));
            }
        }
        return dist[dest_i][dest_j];
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        Graph graph(heights);
        return dijkstra(graph, 0, 0, heights.size() - 1, heights[0].size() - 1);
    }
};