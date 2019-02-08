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
    ListNode *h = nullptr;
    ListNode *reverse(ListNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (node->next == nullptr) {
            h = node;
            return node;
        }
        
        ListNode *n = reverse(node->next);
        n->next = node;
        node->next = nullptr;
        return node;
    }
    
    ListNode* reverseList(ListNode* head) {
        reverse(head);
        return h;
    }
};