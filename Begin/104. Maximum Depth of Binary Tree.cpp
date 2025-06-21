// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
    int max_diameter = 0;

    // 求子树最大深度，同时更新每个结点的diameter
    int getDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        int depth = max(left, right) + 1;
        int curr_diameter = left + right;
        if (max_diameter < curr_diameter)
            max_diameter = curr_diameter;
        return depth;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        getDepth(root);
        return this->max_diameter;
    }
};