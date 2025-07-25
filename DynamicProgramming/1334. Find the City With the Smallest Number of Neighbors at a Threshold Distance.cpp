// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // dp_table[i][j]存储从i到j的最短路径长度
        vector<vector<int>> dp_table(n, vector<int>(n, INT_MAX));
        // 初始化自环
        for (int i = 0; i < n; ++i)
        {
            dp_table[i][i] = 0;
        }
        // 初始化直接相邻的结点
        for (const auto edge : edges)
        {
            // 无向图的边是双向的
            dp_table[edge[0]][edge[1]] = edge[2];
            dp_table[edge[1]][edge[0]] = edge[2];
        }
        // 三层循环
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (dp_table[i][k] != INT_MAX && dp_table[k][j] != INT_MAX)
                    {
                        dp_table[i][j] = min(dp_table[i][j], dp_table[i][k] + dp_table[k][j]);
                    }
                }
            }
        }
        // 统计最短路径权重小于distanceThreshold的节点
        int result_node = -1;
        int result_count = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            // 统计结点i
            int count = 0;
            for (int j = 0; j < dp_table[i].size(); ++j)
            {
                if (i == j)
                    continue; // 跳过自环
                if (dp_table[i][j] <= distanceThreshold)
                    count++; // 边i-->j
            }
            // 更新路径距离限制为`distanceThreshold`以内可到达城市最少的城市
            if (count <= result_count)
            {
                result_node = i;
                result_count = count;
            }
        }
        return result_node;
    }
};