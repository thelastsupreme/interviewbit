
//prabhaths code
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *curr,*nxt;
    curr=A;
    while(curr->next!=NULL)
    {
        nxt=curr->next;
        while(curr->val==nxt->val)
        {
            if(nxt->next==NULL)
            {
                curr->next=NULL;
                return A;
            }
            nxt=nxt->next;
        }
        curr->next=nxt;
        curr=nxt;
    }
    return A;
}
//krutikas code
ListNode* Solution::deleteDuplicates(ListNode* A) {

    ListNode* temp=A;
    ListNode* i=A;
    int value=A->val;
    int flag=0;
    if(A==NULL)
        return NULL;
    if(A->next==NULL)
        return A;
    while(i->next!=NULL)
    {
        if(i->val==value&&flag==0)
        {
            temp=i;
            flag=1;
        }
        else if(i->val!=value)
        {
            temp->next=i->next;
            flag=0;
            value=i->val;
        }
        i=i->next;

    }
    temp->next=NULL;
    return A;
}
//prakritis code
ListNode* Solution::deleteDuplicates(ListNode* A)
{
    if(!A || !A->next)
        return A;
    ListNode* res = A;
    while(A->next)
    {
        if(A->val == A->next->val)
            A->next = A->next->next;
        else
            A = A->next;
    }
    return res;

}
