int intersectPoint(Node* head1, Node* head2)
{
    int c1=0, c2=0;
    Node *p1 = head1;
    Node *p2 = head2;
    while(p1)
    {
        c1++;
        p1=p1->next;
    }
    while(p2)
    {
        c2++;
        p2 = p2->next;
    }
    p1 = head1;
    p2 = head2;
    int diff = abs(c1-c2);
    if(c1>c2)
    {
        while(diff) 
        {
            p1=p1->next;
            diff--;
            
        }
    }
    else if(c1<c2)
    {
        diff = abs(c1-c2);
        while(diff)
        {
            p2 = p2->next;
            diff--;
        }
    }
    while(p1&&p2)
    {
        if(p1==p2) return p1->data;
        else
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return -1;

}
