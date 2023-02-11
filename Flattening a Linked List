// ------------- code of merge two sorted linked list---------------

Node* solve(Node* list1, Node* list2){

        Node* curr1 = list1;
        Node* curr2 = list2;
        Node* next1 = curr1->bottom;
        Node* next2 = curr2->bottom;

        if(curr1->bottom == NULL){
            curr1->bottom=list2;
            return curr1;
        }

        while(next1!=NULL && curr2!=NULL){
        if((curr2->data >= curr1->data) && curr2->data<=next1->data){
            curr1->bottom = curr2;
            next2 =curr2->bottom;
            curr2->bottom = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->bottom;
            if(next1==NULL){
                curr1->bottom = curr2;
                return list1;
            }
        }
        }
        return list1;
    }
    Node* merge(Node* list1, Node* list2) {
        
        if(list1==NULL&&list2==NULL) return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        if(list1->data <= list2->data){
            return solve(list1,list2);
        }
        else{
            return solve(list2,list1);
        }

    }
/*  Function which returns the  root of 
    the flattened linked list. */
//-------------------------------------------------------------------------


Node *flatten(Node *root)
{
   // Your code here
   
   // base case
   if(root->next==NULL){
       return root;
   }
   
   // recursive call
   Node* down = root; 
   Node* right = flatten(root->next); 
   
   // merge the sorted list
   
   return merge(down,right);
}

