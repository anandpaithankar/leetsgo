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
    void inorder(TreeNode *node, std::vector<int>& vals) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
		std::vector<int> vals;
		inorder(root, vals);
		TreeNode *result = new TreeNode(0), *current = result;
		for (auto v : vals) {
			current->right = new TreeNode(v);
			current = current->right;
		}
		return result->right;
    }
    
    
};

