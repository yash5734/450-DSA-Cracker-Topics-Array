/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next == NULL) return NULL;
        int n =0;
        ListNode* cur = head;
        ListNode* curr = head;
        while(cur){
            cur = cur->next;
            n++;
        }
        curr = head;

        int i=0;

        while(i<n/2-1){
            curr = curr->next;
            i++;
        }
        if(curr->next->next!=NULL)
        curr->next = curr->next->next;
        else curr->next = NULL;
        return head;
    }
};
