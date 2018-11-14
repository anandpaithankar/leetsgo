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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currentA = headA;
        ListNode *currentB = headB;
        
        // traverse both the lists at the same time.
        while (currentA != currentB)
        {
            if (currentA != nullptr)
            {
                currentA = currentA->next;
            }
            else
            {
                // headA has reached an end of the list, since
                // we are appending headB to headA (appending lists)
                // set this pointer to go over headB now
                currentA = headB;
            }
            
            if (currentB != nullptr)
            {
                currentB = currentB->next;
            }
            else
            {
                currentB = headA;
            }
        }
        
        return currentA;        
        
    }
};