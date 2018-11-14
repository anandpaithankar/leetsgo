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
    ListNode *p;
    
    bool isPalindrome(ListNode* head) {
        p = head;
        return validatePalindrome(head);
    }
    
    bool validatePalindrome(ListNode *head)
    {
        if (head == nullptr) 
        {
            return true;            
        }
        
        if (validatePalindrome(head->next))
        {
            if (p->val == head->val)
            {
                p = p->next;
                return true;
            }            
        }
        
        return false;
       
    }
};