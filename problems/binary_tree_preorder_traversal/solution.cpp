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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        std::vector<int> result;
        std::stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            auto n = st.top();
            st.pop();
            
            result.push_back(n->val);
            if (n->right) {
                st.push(n->right);
            }
            
            if (n->left) {
                st.push(n->left);
            }
        }
        return result;
    }
};