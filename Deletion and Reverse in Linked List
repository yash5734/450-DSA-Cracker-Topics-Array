/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{

// Your code goes here
Node * curr = *head;
while(curr->next != *head){
    if(curr->next->data==key){
        curr->next = curr->next->next;
    }
    curr= curr->next;
}

}

/* Function to reverse the linked list */
 void reverse(struct Node** head)
{

// Your code goes here
Node* prev = *head;
Node* next = NULL;
while(prev->next != *head){
    prev = prev->next;
}
Node* curr = *head;
do{
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}while(next!=*head);
*head = prev;
}
