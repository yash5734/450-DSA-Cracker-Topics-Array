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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        head = second;
        ListNode* prev = NULL;
        while(first!=NULL && second!=NULL){
            ListNode* temp = first;
            first->next = second->next;
            second->next = temp;

            
            if(prev!=NULL){
                prev->next = second;
            }
            prev = temp;
            if (first->next) {
                first = first->next;
            } else {
                break; // Break the loop if there's no next pair
            }

            if (first->next) {
                second = first->next;
            } else {
                break; // Break the loop if there's no next pair
            }
        }
        return head;
    }
};
