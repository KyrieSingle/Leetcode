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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        n = n - m + 1;
        ListNode* prev = NULL;
        ListNode* current = head;
        while(--m && current) {
            prev = current;
            current = current->next;
        }
        ListNode* s = prev;
        ListNode* s2 = current;
        ListNode* next;

        while(n && current) {
            --n;
            next = current->next;
            current->next = prev;
            prev = current;
            current->next;
        }

        if(s) s->next = pre;
        if(s2) s2->next = current;

        return s ? head : prev;
    }
};
