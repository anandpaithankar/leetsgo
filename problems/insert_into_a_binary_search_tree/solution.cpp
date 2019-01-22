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
    TreeNode *modifiedLevelOrder(TreeNode *root, int val) {
		if (root == nullptr) {
			return new TreeNode(val);
		}
		
		if (root->val > val) {
			root->left = modifiedLevelOrder(root->left, val);
		} else {
			root->right = modifiedLevelOrder(root->right, val);
		}
        
        return root;
	}
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return modifiedLevelOrder(root, val);
    }
};