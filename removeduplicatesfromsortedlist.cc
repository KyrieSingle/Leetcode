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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newHead = head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur) {
            ListNode* next = cur->next;
            bool valid = true;
            if(next && next->val == cur->val) {
                valid = false;
            }
            if(valid) {
                pre = cur;
                cur = next;
            } else {
                int val = cur->val;
                ListNode* deleteNode = cur;
                while(deleteNode && deleteNode->val == val) {
                    next = deleteNode->next;
                    delete deleteNode;
                    deleteNode = next;
                }
                
                if(pre == NULL)
                    newHead = next;
                else 
                    pre->next = next;
                cur = next;
            }
        }
        return newHead;
    }
};
