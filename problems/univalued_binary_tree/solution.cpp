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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } 
        
        int rootVal = root->val;
        if ((root->left && rootVal != root->left->val) ||
            (root->right && rootVal != root->right->val)) {
            return false;
        }
        
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};