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
        
    TreeNode *buildTreeHelper(vector<int>& inorder, vector<int>& preorder, int inStart, 
                              int inEnd, int &preIndex) {
        if (inStart > inEnd) {
            return nullptr;
        }
        
        TreeNode *node = new TreeNode(preorder[preIndex++]);
        if (inStart == inEnd) {
            return node;
        }
        
        int searchIndex = search(inorder, inStart, inEnd, node->val);
        assert(searchIndex != -1);
        
        node->left = buildTreeHelper(inorder, preorder, inStart, searchIndex-1, preIndex);
        node->right = buildTreeHelper(inorder, preorder, searchIndex+1, inEnd, preIndex);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int size = inorder.size()-1;
        return buildTreeHelper(inorder, preorder, 0, size, preIndex);
    }
};