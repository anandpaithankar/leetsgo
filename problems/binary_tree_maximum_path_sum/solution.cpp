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
    int maxSum;
public:
    int findMax(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = findMax(root->left);
        int right = findMax(root->right);
        maxSum = std::max(maxSum, left+right+root->val);
        int ret = root->val + std::max(left, right);
        return ret > 0 ? ret : 0;
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        findMax(root);
        return maxSum;
    }
};