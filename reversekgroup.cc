#include <stdio.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *result = new ListNode(-1);
        result->next = head;
        
        if(head == NULL || k == 1) return head;
        ListNode *pre = result, *cur = head, *post = head->next;
        while(cur) {
            post=cur->next;
            int i = 0;
            while(i < k-1 && post!=NULL) {
                ListNode *temp = post->next;
                post->next = cur;
                cur = post;
                post = temp;
                ++i;
            }
            if(i != k-1) {
                int j = 0;
                ListNode *temp = post;
                post = cur;
                cur = temp;
                while(j < i) {
                    temp = post->next;
                    post->next = cur;
                    cur = post;
                    post = temp;
                    ++j;
                }
                break;
            }
            ListNode *temp = pre->next;
            pre->next = cur;
            temp->next = post;
            pre = temp;
            cur = pre->next;
        }
        
        return result->next;
    }
};
int main(){
    Solution solution;

    return 0;
}
