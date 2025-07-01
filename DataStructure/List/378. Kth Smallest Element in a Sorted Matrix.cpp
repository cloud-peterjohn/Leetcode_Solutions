// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution
{
private:
    class Element
    {
    public:
        int num;
        int i;
        int j;
        Element(int num, int i, int j) : num(num), i(i), j(j) {}
    };
    struct Compare
    {
        bool operator()(Element &e1, Element &e2)
        {
            return e1.num > e2.num;
        }
    };

public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<Element, vector<Element>, Compare> queue;
        for (int i = 0; i < matrix.size(); ++i)
            queue.push(Element(matrix[i][0], i, 0));
        int k_cnt = 0;
        while (!queue.empty())
        {
            Element e = queue.top();
            queue.pop();
            if (e.j + 1 < matrix[e.i].size())
            {
                queue.push(Element(matrix[e.i][e.j + 1], e.i, e.j + 1));
            }
            ++k_cnt;
            if (k_cnt == k)
                return e.num;
        }
        return -1;
    }
};