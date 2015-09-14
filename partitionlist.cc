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
    ListNode* partition(ListNode* head, int x) {
       ListNode* cur = new ListNode(0);
       cur->next = head;
       head = cur;
       while(cur->next && cur->next->val < x) {
            cur = cur->next;
       }
       ListNode* insPos = cur;
       ListNode* temp = NULL;
       while(cur->next) {
            if(cur->next->val < x) {
                temp = cur->next;
                cur->next = temp->next; 
                temp->next = insPos->next;
                insPos->next = temp;
                insPos = insPos->next;
            } else {
                cur = cur->next;
            }
       }
       return head->next;
    }
};
