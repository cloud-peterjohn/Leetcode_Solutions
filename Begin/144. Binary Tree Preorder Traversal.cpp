// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
    vector<int> result;
    void preorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        this->result.push_back(root->val);
        if (root->left)
            preorder(root->left);
        if (root->right)
            preorder(root->right);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        preorder(root);
        return result;
    }
};