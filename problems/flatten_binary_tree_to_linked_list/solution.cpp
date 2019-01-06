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
    void flatten(TreeNode* root) {
        std::stack<TreeNode*> st;
        TreeNode *result = root;
        
        while (root != nullptr || !st.empty())
        {
            if (root->right != nullptr) {
                st.push(root->right);
            }
            
            root->right = root->left;
            root->left = nullptr;
            
            if (root->right == nullptr && !st.empty()) {
                root->right = st.top();
                st.pop();
            }
            
            root = root->right;
        }
        
        root = result;        
    }
};