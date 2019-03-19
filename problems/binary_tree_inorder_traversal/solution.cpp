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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        std::stack<TreeNode*> st;
        TreeNode *current = root;
        
        while (!st.empty() || current != nullptr) {
            while (current) {
                st.push(current);
                current = current->left;
            }
            
            current = st.top();
            st.pop();
            result.push_back(current->val);
            current = current->right;
        }
        return result;
    }
};