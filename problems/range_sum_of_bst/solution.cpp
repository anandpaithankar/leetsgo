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
    int sum = 0;
	
	void modifiedInorder(TreeNode *node, int L, int R) {
		if (!node) {
			return;
		}
		
		if (node->val >= L && node->val <= R) {
			sum += node->val;
		}
		
		if (node->val >= L) {
			modifiedInorder(node->left, L, R);
		}
		
		if (node->val <= R) {
			modifiedInorder(node->right, L, R);
		}	
	}
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        modifiedInorder(root, L, R);
        return sum;
    }
};