//prabhaths code from comments section
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* start = new ListNode(1);
    start->next=A;
    while(start->next)
    {
        if(start->next->val >=B)
            break;
        start = start->next;
    }
    ListNode* curr = start->next;
    ListNode* nxt;
    while(curr->next!=NULL)
        {
            if(curr->next->val < B)
            {
                nxt = curr->next;
                curr->next = nxt->next;
                if(start->next == A)
                {
                    nxt->next = A;
                    A = nxt;
                    start = nxt;
                }
                else
                {
                    nxt->next = start->next;
                    start->next = nxt;
                    start = nxt;
                }
            }
        else
            curr = curr->next;
        }
    return A;
}
//krutikas code
ListNode* Solution::partition(ListNode* A, int B) {

    if(A->next==NULL)
       return A;
    ListNode* curr=A;
    ListNode* prv=A;
    ListNode* temp=A;
    while(curr!=NULL&&curr->next!=NULL)
    {

        if(curr->val<B)
        {

            prv->next=curr->next;   //deleting
            curr->next=temp->next;  // node to be inserted point to head ka next
            temp->next=curr;  // head ka next points to the new node
            curr=prv->next;

        }
        else{
            prv=curr;
            curr=curr->next;
        }

    }
    return A;
}
//prakritis code
 ListNode* reverseList(ListNode* A)
{
    struct ListNode* next;
    struct ListNode* prev;
    struct ListNode* curr;
    prev=NULL;
    curr=A;
    while(curr!= NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
ListNode* Solution::partition(ListNode* A, int B)
{ //1->4->3->2->5->2
    if(!A || !A->next)
        return A;
    ListNode* var1=NULL, *var2=NULL, *a=NULL, *b=NULL;
    while (A)
    {
        if(A->val < B)
        {
            if(!var1)
                a = var1 = A;
            else
            {
                var1->next = A;
                var1 = var1->next;
            }
            A=A->next;
        }
        else
        {
            if(!var2)
                b = var2 = A;
            else
            {
                var2->next = A;
                var2 = var2->next;
            }
            A=A->next;
        }
    }
    if(a)
        var1->next = NULL;

    if(b)
    {
        var2->next = a;
        reverseList(b);
        return b;
    }
    reverseList(a);
    return a;

}
