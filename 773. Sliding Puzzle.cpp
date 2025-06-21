// https://leetcode.com/problems/sliding-puzzle/description/

class Solution
{
private:
    class Board
    {
    public:
        vector<vector<int>> board;
        int step;
        Board(vector<vector<int>> &board, int step)
        {
            this->board = board;
            this->step = step;
        }
    };

    Board swap(Board b, int i1, int j1, int i2, int j2)
    { // 拷贝传值，避免修改原board
        int temp = b.board[i1][j1];
        b.board[i1][j1] = b.board[i2][j2];
        b.board[i2][j2] = temp;
        ++b.step;
        return b;
    }

public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        queue<Board> q;
        vector<Board> visited;
        q.push(Board(board, 0));
        while (!q.empty())
        {
            // 遍历当前结点
            Board b = q.front();
            q.pop();
            visited.push_back(b);

            // 如果遍历至目标board，则结束
            if (b.board == vector<vector<int>>{{1, 2, 3}, {4, 5, 0}})
                return b.step;

            // 计算邻居结点（上下左右交换一次后的board）
            vector<Board> neighbours;
            if (b.board[0][0] == 0)
            {
                neighbours.push_back(swap(b, 0, 0, 0, 1));
                neighbours.push_back(swap(b, 0, 0, 1, 0));
            }
            else if (b.board[0][1] == 0)
            {
                neighbours.push_back(swap(b, 0, 1, 0, 0));
                neighbours.push_back(swap(b, 0, 1, 0, 2));
                neighbours.push_back(swap(b, 0, 1, 1, 1));
            }
            else if (b.board[0][2] == 0)
            {
                neighbours.push_back(swap(b, 0, 2, 0, 1));
                neighbours.push_back(swap(b, 0, 2, 1, 2));
            }
            else if (b.board[1][0] == 0)
            {
                neighbours.push_back(swap(b, 1, 0, 0, 0));
                neighbours.push_back(swap(b, 1, 0, 1, 1));
            }
            else if (b.board[1][1] == 0)
            {
                neighbours.push_back(swap(b, 1, 1, 1, 0));
                neighbours.push_back(swap(b, 1, 1, 0, 1));
                neighbours.push_back(swap(b, 1, 1, 1, 2));
            }
            else if (b.board[1][2] == 0)
            {
                neighbours.push_back(swap(b, 1, 2, 0, 2));
                neighbours.push_back(swap(b, 1, 2, 1, 1));
            }

            // 将其邻居结点加入队列
            for (auto neighbour : neighbours)
            {
                // 避免死循环
                bool is_dulplicate = false;
                for (const auto vnode : visited)
                {
                    if (vnode.board == neighbour.board)
                    {
                        is_dulplicate = true;
                        break;
                    }
                }
                if (is_dulplicate)
                    continue;

                q.push(neighbour);
            }
        }
        return -1;
    }
};