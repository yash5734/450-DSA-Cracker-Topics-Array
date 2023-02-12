class Solution
{
    public:
    
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        int carry  = 1;
        Node* curr = reverse(head);
        Node* temp = curr;
        while(curr!=NULL){
            // int data = curr->data;
            curr->data = curr->data+carry;
            carry = 0;
            if(curr->data>9){
                carry = 1;
                curr->data = 0;
            }
            curr = curr->next;
        }
        Node* curr2 = head;
        if(carry == 1){
            while(curr2->next!=NULL){
                curr2 = curr2->next;
            }
            curr2->next = new Node(1);
        }
        head = reverse(temp);
        return head;
        
    }
};
