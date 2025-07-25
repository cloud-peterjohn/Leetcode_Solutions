// https://leetcode.com/problems/cheapest-flights-within-k-stops/

// Dijkstra
class Solution
{
private:
    struct State
    {
        int node;
        int distance;
        int edge;
        State(int node, int distance, int edge) : node(node), distance(distance), edge(edge) {}
    };
    struct Compare
    {
        bool operator()(const State &s1, const State &s2)
        {
            return s1.distance > s2.distance;
        }
    };

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // 将航班信息转化为图
        vector<vector<int>> graph(n);
        vector<vector<int>> weights(n, vector<int>(n, INT_MAX));
        for (const auto flight : flights)
        {
            int from_i = flight[0], to_i = flight[1], price_i = flight[2];
            graph[from_i].push_back(to_i);
            weights[from_i][to_i] = price_i;
        }

        vector<vector<int>> distance(n, vector<int>(k + 2, -1)); // distance[i][j]记录src到node_i经过j条边的最短路径，初始化为-1（最多允许k + 1条边，长度设置为k + 2）
        priority_queue<State, vector<State>, Compare> pq;
        pq.push(State(src, 0, 0));
        while (!pq.empty())
        {
            State s = pq.top();
            pq.pop();

            // 到达dest
            if (s.node == dst)
                return s.distance;
            // 不是第一次出栈的dest，直接跳过
            if (distance[s.node][s.edge] != -1)
                continue;
            // 如果是第一次出栈的dest，则更新最短路径
            distance[s.node][s.edge] = s.distance;

            // 邻居结点入栈
            for (const auto neigh : graph[s.node])
            {
                // 如果超出了最长边数（最多k个stops-->k+1条边），则邻居节点不满足要求
                if (s.edge + 1 > k + 1)
                    break;
                // 如果不是第一次出栈的dest，也不是更少边数的情况，直接跳过
                if (distance[neigh][s.edge + 1] != -1)
                    continue;
                // 入栈
                pq.push(State(neigh, s.distance + weights[s.node][neigh], s.edge + 1));
            }
        }
        return -1;
    }
};

// DP
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 将航班信息转化为图
        vector<vector<int>> graph(n);   // graph[i]存储目的地为i的所有航线出发点
        vector<vector<int>> weights(n, vector<int>(n, 999999));
        for (const auto flight : flights) {
            int from_i = flight[0], to_i = flight[1], price_i = flight[2];
            graph[to_i].push_back(from_i);
            weights[from_i][to_i] = price_i;
        }

        // dp_table[i][j]是从`src`到`i`且不超过`j`次中转的最短路径长度。
        vector<vector<int>> dp_table(n, vector<int>(k + 1, 999999));
        // base case: 中转次数为0直达(dp_table[i][0])
        for (int i = 0; i < n; ++i) {
            if (i == src) dp_table[i][0] = 0;
            else {
                if (weights[src][i] < 999999) dp_table[i][0] = weights[src][i];    //直达
                else dp_table[i][0] = 999999;  // 不可直达
            }
        }
        // DP：遍历所有中转次数
        for (int j = 1; j < k + 1; ++j) {
            // 遍历所有目的地
            for (int i = 0; i < n; ++i) {
                // 原地不动
                if (i == src) dp_table[i][j] = 0;
                for (const auto transfer : graph[i]) {
                    dp_table[i][j] = min(dp_table[i][j], dp_table[transfer][j - 1] + weights[transfer][i]);
                }
            }
        }
        if (dp_table[dst][k] == 999999) return -1;  // 不可达
        else return dp_table[dst][k];
    }
};
