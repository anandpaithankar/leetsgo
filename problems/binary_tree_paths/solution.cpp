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
    
    void binaryTreePathHelper(TreeNode *root, std::string path, std::vector<std::string> & paths) {
        if (root == nullptr) {
            return;
        }
        
        path += std::to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(path);
        } else {
            path+= "->";
            binaryTreePathHelper(root->left, path, paths);
            binaryTreePathHelper(root->right, path, paths);
        }
        
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<string> paths;
        std::string path;
        
        binaryTreePathHelper(root, path, paths);
        return paths;
    }
};