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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* current;
        current = head->next;
        if(!head->next->next) {
        	head->next = NULL;
        	current->next = head;
        	return current;
        }
        ListNode* prev;
        ListNode* temp;

        head->next = NULL;
        prev = current->next;
        current->next = head;
        while(prev->next) {
        	temp = prev->next;
        	prev->next = current;
        	current = prev;
        	prev = temp;
        }
        prev->next = current;
        return prev;
    }
};