// https://leetcode.com/problems/minimum-depth-of-binary-tree/

// Implemented by BFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    class State
    {
    public:
        TreeNode *node;
        int depth;
        State() : node(nullptr), depth(0) {}
        State(TreeNode *node, int depth) : node(node), depth(depth) {}
    };
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<State> q;
        q.push(State(root, 1));
        while (!q.empty())
        {
            State s = q.front();
            q.pop();

            if (s.node->left)
                q.push(State(s.node->left, s.depth + 1));
            if (s.node->right)
                q.push(State(s.node->right, s.depth + 1));

            if ((s.node->left == nullptr) && (s.node->right == nullptr))
            {
                // 层序遍历到的第一个结点就是最小深度的结点
                return s.depth;
            }
        }
        return -1;
    }
};

// Implemented by DFS (每个结点保存一份depth)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    class State
    {
    public:
        TreeNode *node;
        int depth;
        State() : node(nullptr), depth(0) {}
        State(TreeNode *node, int depth) : node(node), depth(depth) {}
    };
    int _min_depth(State s)
    {
        if ((!s.node->left) && (!s.node->right))
            return s.depth;

        int left_depth = 99999;
        int right_depth = 99999;
        if (s.node->left)
            left_depth = _min_depth(State(s.node->left, s.depth + 1));
        if (s.node->right)
            right_depth = _min_depth(State(s.node->right, s.depth + 1));

        return min(left_depth, right_depth);
    }
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return _min_depth(State(root, 1));
    }
};

// Implemented by DFS (类内全局变量：当前结点深度curr_depth和min_depth)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int curr_depth = 1;
    int min_depth = 99999;

    void _min_depth(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
        {
            ++curr_depth;
            _min_depth(root->left);
        }
        if (root->right)
        {
            ++curr_depth;
            _min_depth(root->right);
        }
        if ((!root->left) && (!root->right))
        {
            min_depth = min(min_depth, curr_depth);
        }
        --curr_depth;
    }
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        _min_depth(root);
        return min_depth;
    }
};