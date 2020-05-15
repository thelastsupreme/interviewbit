//krutikas code
ListNode* Solution::rotateRight(ListNode* A, int B) {

    ListNode* t=A; int len=0;
    while(t->next!=NULL)
    {
        t=t->next;
        len++;
    }
    t->next=A;
    len++;
    int k=len-(B%len);
    int i=0;
    while(i<k)
    {
        t=A;
        A=A->next;
        i++;
    }
    t->next=NULL;
    return A;
}

//prabhath code
int length (struct ListNode *head)
{
    struct ListNode *cur=head;
    int count=0;
    for(cur=head;cur!=NULL;cur=cur->next)
    {
        count++;
    }
    return count;
}
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int len=length(A);
    ListNode *temp=A;
    for(int i=0;i<len-(B%len);i++)
    {
        temp=temp->next;
    }
    ListNode *res= new ListNode(0);
    ListNode *a=res;
    while(temp!=NULL)
    {
        a->next=temp;
        temp=temp->next;
        a=a->next;
    }
    for(int i=0;i<len-(B%len);i++)
    {
        a->next=A;
        A=A->next;
        a=a->next;
    }
    a->next=NULL;
    return res->next;
}
