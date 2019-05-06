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
    void kthSmallest(TreeNode *root, int k, int &count, int &val) {
        if (root == nullptr || count >= k) {
            return;
        }
        
        kthSmallest(root->left, k, count, val);
        
        count++;
        if (count == k) {
            val = root->val;
            return;
        }
        
        kthSmallest(root->right, k , count, val);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, val =INT_MIN;
        kthSmallest(root, k, count, val);
        return val;
    }
};