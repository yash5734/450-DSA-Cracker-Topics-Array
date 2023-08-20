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
    private:
    ListNode* reverse(ListNode* head){

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {

        if(head==NULL||head->next == NULL) return NULL;
        int n =0;
        ListNode* curr = head;
        while(curr){
            n++;
            curr=curr->next;
        }
        curr = head;
        ListNode* head2 = head;

        int i=0;
        while(i<n/2-1){
            curr = curr->next;

            i++;
        }
        head2 = curr->next;
        curr->next = NULL;

        ListNode* head1 = reverse(head);

        // cout<<head1;

        int maxi =0;

        while(head1 && head2){
            int sum = head1->val + head2->val;
            head1 = head1->next;
            head2 = head2->next;

            maxi = max(maxi,sum);
        }

        return maxi;

    }
};
