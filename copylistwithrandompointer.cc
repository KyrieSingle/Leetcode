/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* newHead = nullptr;
        if(head == nullptr) return nullptr;
        RandomListNode* cur = haed;
        RandomListNode* cur_cp = nullptr;
        while(cur != nullptr) {
        	cur_cp = new RandomListNode(cur->label);
        	cur_cp->next = cur->next;
        	cur->next = cur_cp;
        	cur = cur_cp->next;
        }
        cur = head;
        while(cur != nullptr) {
        	cur_cp = cur->next;
        	if(cur->random) {
        		cur_cp->random = cur->random->next;
			}
			cur = cur_cp->next;
        }
        cur = head;
        newHead = head->next;
        while(cur != nullptr) {
        	cur_cp = cur->next;
            cur->next = cur_cp->next;
            cur = cur->next;
            if (cur)
                cur_cp->next = cur->next;
        }
        
        return newHead;
    }
};