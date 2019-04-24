/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *list;
public:
    TreeNode *sortedListToBST(int start, int end) {
        if (start > end){
            return nullptr;
        }
        
        int mid = (start + end ) / 2;
        TreeNode *leftChild = sortedListToBST(start, mid-1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        parent->right = sortedListToBST(mid+1, end);
        return parent;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode *p = head;
        // Compute the length of a list
        while (p != nullptr) {
            p = p->next;
            n++;
        }
        list = head; // set the global
        return sortedListToBST(0, n-1);
    }
};