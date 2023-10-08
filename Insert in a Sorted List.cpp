class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int n) {
        // Code here
        if(head==NULL||head->next==NULL) return head;
        
        if(head->data > n){
            Node* temp = new Node(n);
            temp->next = head;
            head = temp;
            return head;
        }
        
        Node* curr = head;
        Node* next = head->next;
        
        while(next!=NULL){
            if(next->data>n){
                Node* temp = new Node(n);
                curr->next = temp;
                temp->next = next;
                break;
            }
            if(next->next == NULL && next->data <= n){
                 Node* temp = new Node(n);
                 next->next = temp;
                 break;
            }
            curr = next;
            next = next->next;
        }
        return head;
        
    }
};
