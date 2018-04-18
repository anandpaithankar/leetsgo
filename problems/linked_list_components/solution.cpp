/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <limit>
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        
        
        int connectedLinks = 0;
        std::unordered_set<int> s(G.begin(), G.end());
        ListNode* p = head;
        while(p) {
            if (s.count(p->val) && ((p->next == nullptr) || !s.count(p->next->val))) {
                connectedLinks++;
            }
            p = p->next;
        }
        
        return connectedLinks;
    }
};