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
    
    int search(vector<int>& inorder, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
        
    TreeNode *buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, 
                              int inEnd, int &postIndex) {
        if (inStart > inEnd) {
            return nullptr;
        }
        
        TreeNode *node = new TreeNode(postorder[postIndex--]);
        if (inStart == inEnd) {
            return node;
        }
        
        int searchIndex = search(inorder, inStart, inEnd, node->val);
        assert(searchIndex != -1);
        
        node->right = buildTreeHelper(inorder, postorder, searchIndex+1, inEnd, postIndex);
        node->left = buildTreeHelper(inorder, postorder, inStart, searchIndex-1, postIndex);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size()-1;
        int size = inorder.size()-1;
        return buildTreeHelper(inorder, postorder, 0, size, postIndex);
    }
};