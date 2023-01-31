class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        Node* temp = head;
        map<Node*,bool> visited;
        while(temp != NULL){
            if(visited[temp] == true) return 1;
            
            visited[temp] = true;
            
            temp = temp->next;
        }
        return 0;
    }
};
