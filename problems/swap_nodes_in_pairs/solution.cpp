/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void swapNodes(ListNode *node) {
        if (node == nullptr || node->next == nullptr) {
            return ;
        }
        
        std::swap(node->val, node->next->val);
        swapNodes(node->next->next);
    }
    
    ListNode* swapPairs(ListNode* head) {
        swapNodes(head);
        return head;
    }
};