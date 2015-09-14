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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = slow;
        ListNode* p = slow->next;
        slow->next = nullptr; 

        while(p) {
            ListNode* tmp = p->next;
            p->next = prev;
            prev = p;
            p = tmp;
        }

        ListNode* left = head;
        ListNode* right = prev;
        while(left && right) {
            if(left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};
