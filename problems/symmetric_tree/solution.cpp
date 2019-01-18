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
    bool isSymmetricHelper(TreeNode* left, TreeNode *right) {
      if (left == nullptr && right == nullptr) {
        return true;
      }

      if (left == nullptr || right == nullptr) {
        return false;
      }

      return (left->val == right->val) && 
      isSymmetricHelper(left->left, right->right) &&
      isSymmetricHelper(left->right, right->left);      
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }        

        return isSymmetricHelper(root->left, root->right);
    }
};