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
public:
    
    int ComputeLinkedListLength(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        while (p != nullptr) {
            p = p->next;
            n++;
        }
        return n;
    }
    
    TreeNode* sortedListToBST(int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) /2;
        TreeNode* left = sortedListToBST(start, mid - 1);
        TreeNode* parent = new TreeNode{list->val};
        parent->left = left;
        list = list->next;
        parent->right = sortedListToBST(mid + 1, end);
        return parent;
    }
    
    ListNode* list;
    TreeNode* sortedListToBST(ListNode* head) {
        int n = ComputeLinkedListLength(head);
        list = head;
        return sortedListToBST(0, n-1);
    }
};