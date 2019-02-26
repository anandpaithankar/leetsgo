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
    ListNode *mergeTwoSortedLists(ListNode *list1, ListNode *list2) {
        ListNode dummy(-1);
        ListNode **current = &(dummy.next);
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                *current = list1;
                list1 = list1->next;
            } else {
                *current = list2;
                list2 = list2->next;
            }
            current = &((*current)->next);
        }
        
        if(list1) {
            *current = list1;
        }
        
        if(list2) {
            *current = list2;  
        }
        
        return dummy.next;
    }
    
    ListNode* sortListHelper(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        }        
        
        // find middle node
        ListNode *slow = head, *fast = head, *preSlow = nullptr;
        while (fast && fast->next) {
            preSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        preSlow->next = nullptr;
        return mergeTwoSortedLists(sortListHelper(head), sortListHelper(slow));
    }
    
    ListNode* sortList(ListNode* head) {
        return sortListHelper(head);
    }
};