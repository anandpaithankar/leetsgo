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
 
    void pathSumHelper(TreeNode *root, int sum, std::vector<int>& path, std::vector<std::vector<int>>& paths) {
        if (root == nullptr) {
            return;
        }
       
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum == root->val) {
            paths.push_back(path);
            path.erase(path.end()-1);
            return;
            
        } else {
            pathSumHelper(root->left, sum - root->val, path, paths);
            pathSumHelper(root->right, sum - root->val, path, paths);
        }        
        path.erase(path.end()-1);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<int> path;
        std::vector<std::vector<int>> paths;
        pathSumHelper(root, sum, path, paths);
        return paths;
        
    }
};