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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
		ListNode *fast = head;
		
		// move fast node by n positions
		for (int i = 0; i < n; i++) {
			fast = fast->next;
		}
		
		if (fast == nullptr) {
			ListNode *t = head->next;
			delete head;
			head = t;
			return head;
		}
		
		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}
		
		ListNode *target = slow->next;
        slow->next = target->next;
        delete target;
		return head;
    }
};