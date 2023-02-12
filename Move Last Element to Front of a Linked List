class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        
        if(head==NULL||head->next==NULL) return head;
        
        ListNode* curr = head;
        ListNode* temp2 = head;
        ListNode* temp = head;
        
        while(curr->next->next!=NULL){
            curr=curr->next;
            temp  = curr;
        }
        
        ListNode* curr2 = temp->next;
        curr2 ->next = temp2;
        temp ->next = NULL;
        return curr2;
        
    }
};
