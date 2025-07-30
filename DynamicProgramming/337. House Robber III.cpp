// https://leetcode.com/problems/house-robber-iii/

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
private:
    unordered_map<TreeNode *, int> map; // 消除重叠子问题
public:
    int rob(TreeNode *root)
    {
        if (!root)
            return 0;
        if (map.find(root) != map.end())
            return map[root];

        // 抢当前房屋，下一层不能抢，从下下一层开始
        int next_next = 0;
        if (root->left)
            next_next = next_next + rob(root->left->left) + rob(root->left->right);
        if (root->right)
            next_next = next_next + rob(root->right->left) + rob(root->right->right);
        int rob_money = root->val + next_next;
        // 不抢当前房屋，从下一层开始
        int not_rob = rob(root->left) + rob(root->right);

        // 存储map中，避免重复计算
        map[root] = max(rob_money, not_rob);
        return max(rob_money, not_rob);
    }
};