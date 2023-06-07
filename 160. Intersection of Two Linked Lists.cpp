/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    int len(ListNode* node){
        int len =0;
        ListNode* temp = node;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if(!headA || !headB) return NULL;
        int len1 = len(headA);
        int len2 = len(headB);
        if(len1>len2){
            while(len1>len2){
            headA = headA->next;
            len1--;
            }
        }else if(len1<len2){
            while(len1<len2){
                headB = headB->next;
                len2--;
            }
        }

        while(headB&&headA){
            if(headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;

    }
};
