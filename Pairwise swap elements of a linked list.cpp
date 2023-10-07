class Solution
{
public:
    Node* pairWiseSwap(struct Node* head) 
    {
        if (head == NULL || head->next == NULL) return head;

        Node* first = head;
        Node* second = head->next;
        // head = head->next;
        Node* prev = NULL;

        while (second != NULL) {
            Node* temp = second->next;
            second->next = first;
            first->next = temp;
            
            if (prev != NULL) {
                prev->next = second;
            } else {
                head = second;
            }
            
            if (temp == NULL) {
                break; // Reached the end of the even-length list
            }
            
            prev = first;
            first = temp;
            second = temp->next;
        }

        return head;
    }
};
