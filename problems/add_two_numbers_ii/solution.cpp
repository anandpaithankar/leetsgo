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
    
    ListNode * addToHead(ListNode *head, int val) {    
        
        if (head == nullptr)
            return new ListNode{val};
        
         ListNode *t = head;
         head = new ListNode{val};
         head->next = t;
         return head;        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> s1;
        std::stack<int> s2;
        
        ListNode *result = nullptr;
        
        for (ListNode *current = l1; current != nullptr; current = current->next)
        {
            s1.push(current->val);
        }
        
        for (ListNode *current = l2; current != nullptr; current = current->next)
        {
            s2.push(current->val);
        }
        
        int carry = 0;
        
        while (!s1.empty() || !s2.empty())
        {
            int sum = carry;
            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            
            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }
            
            carry = 0;            
            if (sum > 9)
            {
                carry = 1;
                sum %= 10;
            }
            
            result = addToHead(result, sum);
        }
        
        if (carry)
        {
            result = addToHead(result, carry);
        }
                
        return result;        
    }
};