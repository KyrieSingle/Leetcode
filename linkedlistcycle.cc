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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        int step=1;
        while(1){
           for(int i=0;i<2*step;i++){
               fast=fast->next;
               if(slow==fast)
                  return true;
               if(fast==nullptr)
                  return false;
           }
           for(int j=0;j<step;j++)
               slow=slow->next;
           step++;
        }
       return false;
    }
};