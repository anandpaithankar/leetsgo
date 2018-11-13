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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *mergedList;
        ListNode **current = &mergedList;
        
        while(l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                *current = l1;
                l1 = l1->next;
            }
            else if (l1->val > l2->val)
            {
                *current = l2;
                l2 = l2->next;
            }
            
            current = &((*current)->next);
        }
        
        if (l1 == nullptr)
        {
            *current = l2;            
        }
        
        if (l2 == nullptr)
        {
            *current = l1;
        }
        
        return mergedList;
        
    }
};