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
    void sumOfLeftLeavesHelper(TreeNode *node, int &sum, bool leftChild) {
        if (node == nullptr) {
            return;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            if (leftChild) {
                sum += node->val;
            }
                
            return;
        }
        
        sumOfLeftLeavesHelper(node->left, sum, true);
        sumOfLeftLeavesHelper(node->right, sum, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root == nullptr) {
            return sum;
        }
        
        sumOfLeftLeavesHelper(root, sum, false);
        return sum;
        
    }
};