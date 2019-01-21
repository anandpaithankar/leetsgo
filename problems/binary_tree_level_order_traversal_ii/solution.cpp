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
    
    void bottomUpHelper(TreeNode *root, std::vector<std::vector<int>>& levels, int level) {
        if (root == nullptr)
            return;
        
        if (levels.size() < level + 1) {
            levels.push_back(std::vector<int>());
        }
        
        levels[level].push_back(root->val);
        bottomUpHelper(root->left, levels, level+1);
        bottomUpHelper(root->right, levels, level+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> levels;
        int level = 0;
        
        bottomUpHelper(root, levels, level);
        std::reverse(levels.begin(), levels.end());
        return levels;
    }
};