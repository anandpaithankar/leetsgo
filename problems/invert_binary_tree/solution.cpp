/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void SwapChildren(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            return;
        }

        TreeNode *t = node->right;
        node->right = node->left;
        node->left = t;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
        {
            return nullptr;
        }

        SwapChildren(root);
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};