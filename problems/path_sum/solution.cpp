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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        
        
        
        int value = sum - root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            return (value == 0);
        }
        
        return hasPathSum(root->left, value) || hasPathSum(root->right, value);
    }
};