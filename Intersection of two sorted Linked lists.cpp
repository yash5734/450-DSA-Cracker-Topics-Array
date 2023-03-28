Node* findIntersection(Node* head1, Node* head2)
{
    Node* curr1 = head1;
    Node* curr2 = head2;
    Node* head3 = new Node(-1);
    Node* curr3 = head3;
    
    while(curr1!=NULL && curr2!=NULL){
        if(curr1->data==curr2->data){
            Node* p = new Node(curr1->data);
            curr3->next = p;
            curr1 = curr1->next;
            curr2 = curr2->next;
            curr3 = curr3->next;
        }
        else if(curr1->data<curr2->data){
            curr1 = curr1->next;
        }
        else if(curr1->data>curr2->data){
            curr2 = curr2->next;
        }
    }
    
    
    return head3->next;
}
