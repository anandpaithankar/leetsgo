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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
		return nullptr;
	
        TreeNode *mergedNode = new TreeNode(0);
        if (t1 != nullptr)
            mergedNode->val += t1->val;
        if (t2 != nullptr)
            mergedNode->val += t2->val;

        if (t1 == nullptr && t2 != nullptr) {
            mergedNode->left = mergeTrees(t1, t2->left);
            mergedNode->right = mergeTrees(t1, t2->right);
        }
        else if (t1 != nullptr && t2 == nullptr) {
            mergedNode->left = mergeTrees(t1->left, t2);
            mergedNode->right = mergeTrees(t1->right, t2);
        } else if (t1 != nullptr && t2 != nullptr) {
            mergedNode->left = mergeTrees(t1->left, t2->left);
            mergedNode->right = mergeTrees(t1->right, t2->right);
        }

        return mergedNode;
    }
};