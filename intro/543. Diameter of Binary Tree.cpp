// https://leetcode.com/problems/diameter-of-binary-tree/

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

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if ((root->left == nullptr) && (root->right == nullptr))
            return 1;

        int left = 0;
        int right = 0;
        if (root->left)
        {
            left = diameterOfBinaryTree(root->left);
        }
        if (root->right)
        {
            right = diameterOfBinaryTree(root->right);
        }

        int curr_diameter = left + right;
        if (max_diameter < curr_diameter)
            max_diameter = curr_diameter;

        return curr_diameter;
    }
};