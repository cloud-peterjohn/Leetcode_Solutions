// https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution
{
private:
    struct State
    {
        int number;
        int x_i;
        int y_i;
        int weight;
    };
    struct Compare
    {
        bool operator()(const State &s1, const State &s2)
        {
            return s1.weight > s2.weight;
        }
    };
    struct Graph
    {
        vector<vector<int>> points;
        int number;
        Graph(vector<vector<int>> &points)
        {
            this->points = points;
            this->number = points.size();
        }
        vector<int> get_point(int no)
        {
            return points[no];
        }
        vector<int> get_neighbours(int no)
        {
            vector<int> neighbours;
            for (int i = 0; i < this->number; ++i)
            {
                if (i != no)
                    neighbours.push_back(i);
            }
            return neighbours;
        }
    };
    int get_distance(int x_i, int y_i, int x_j, int y_j)
    {
        return abs(x_j - x_i) + abs(y_j - y_i);
    }
    int prim(Graph &graph)
    {
        int min_cost = 0;
        vector<bool> visited(graph.number, false);
        priority_queue<State, vector<State>, Compare> pq;
        pq.push(State(0, graph.points[0][0], graph.points[0][1], 0));
        while (!pq.empty())
        {
            State s = pq.top();
            pq.pop();
            if (visited[s.number])
                continue;
            visited[s.number] = true;
            min_cost += s.weight;
            for (int no : graph.get_neighbours(s.number))
            {
                if (visited[no])
                    continue;
                vector<int> neigh_point = graph.get_point(no);
                pq.push(State(no, neigh_point[0], neigh_point[1], get_distance(s.x_i, s.y_i, neigh_point[0], neigh_point[1])));
            }
        }
        return min_cost;
    }

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        // 构建邻接矩阵
        Graph graph(points);
        // Prim算法
        return prim(graph);
    }
};