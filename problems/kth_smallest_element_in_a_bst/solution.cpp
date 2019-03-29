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
    int kthSmallest(TreeNode *root, int &i ,int k) {
        if (root == nullptr) {
            return INT_MAX;
        }
        
        // search left subtree
        int left = kthSmallest(root->left, i, k);
        
        if (left != INT_MAX) {
            return left;
        }
        
        // current element is kth smallest element
        if (++i == k) {
            return root->val;
        }
        
        return kthSmallest(root->right, i, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return kthSmallest(root, i, k);
    }
};