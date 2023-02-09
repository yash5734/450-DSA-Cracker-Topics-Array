class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    
    void insertAt(Node* &tail,Node* curr){
        tail->next = curr;
        tail = curr;
    }
    Node* segregate(Node *head) {
        
        // Add code here
        
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* curr = head;
        
        while(curr!=NULL){
            
            if(curr->data == 0){
                insertAt(zeroTail,curr);
            }
            else if(curr->data == 1){
                insertAt(oneTail,curr);
            }
            else if(curr->data == 2){
                insertAt(twoTail,curr);
            }
            
            curr = curr->next;
        }
        
        //merge
        
        if(oneHead->next!=NULL){
            zeroTail->next = oneHead->next;
        }
        else{
            zeroTail->next = twoHead->next;
        }
        
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        head = zeroHead->next;
        
        delete oneHead;
        delete zeroHead;
        delete twoHead;
        
        
        return head;
        
    }
};
