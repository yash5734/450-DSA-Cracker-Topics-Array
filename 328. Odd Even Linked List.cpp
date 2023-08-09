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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)  return head;
        ListNode* even = head;
        ListNode* odd = head->next;
        ListNode* head2 = head->next;

        while(odd && odd->next != NULL){
            even->next = NULL;
            even->next = odd->next;
            even = even->next;

            odd->next = even->next;
            odd= odd->next;

        }
        even->next = head2;
        return head;

    }
};
