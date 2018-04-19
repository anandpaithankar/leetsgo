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
    
    TreeNode* BSTHelper(std::vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        
        int mid = start + (end - start) / 2;
        TreeNode* n = new TreeNode{nums[mid]};
        n->left = BSTHelper(nums, start, mid - 1);
        n->right = BSTHelper(nums, mid + 1, end);
        return n;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BSTHelper(nums, 0, nums.size() - 1);
    }
};