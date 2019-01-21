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
    void getLeaves(TreeNode *root, std::vector<int>& leafs) {
		if (!root) {
			return;
		}
		
		if (root->left == nullptr && root->right == nullptr) {
			leafs.push_back(root->val);
			return;
		}
		
		getLeaves(root->left, leafs);
		getLeaves(root->right, leafs);
	}
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> l1;
		getLeaves(root1, l1);
		
		std::vector<int> l2;
		getLeaves(root2, l2);
		
		return (l1 == l2);
    }
};