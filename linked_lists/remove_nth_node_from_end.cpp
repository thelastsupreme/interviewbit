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
//krutikas code
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {

    if(A->next==NULL)
        return NULL;
    reverseList(A);
    int i=0;
    int flag=0;

    ListNode* prev=A;
    ListNode* curr=A;
    while(i<B)
    {
        prev=curr;
        curr=curr->next;
        i++;
        if(i==B)
          flag=1;
    }
    if(flag)
    {
        prev->next=curr->next;
    }
    else
    {
        A=A->next;
    }
    reverseList(A);
    return A;
}
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
//prakritis code
ListNode* Solution::removeNthFromEnd(ListNode* A, int B)
{
    if(!A)
        return A;
    if(A->next==NULL)
        return NULL;
    ListNode *curr=A;
    int len= length(A);
    if(B<len)
    {
        int itr = len-B;
        for(int i=0; i<itr-1; i++)
        {
            curr=curr->next;

        }
        if(curr->next->next==NULL)
                curr->next=NULL;
        else
                curr->next=curr->next->next;
    return A;
    }
    else if(B>=len)
    {
        ListNode * temp=A;
        A=A->next;
        delete temp;
        return A;
    }
}
//prabhaths code
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(A->next==NULL)
        return NULL;
    int n=length(A);
   // cout<<n<<endl;
    if(n==0)
        return A;
    if(B==0)
        B++;
    int k=n-B;
    if(k<=0)
        return A->next;
    ListNode *curr=A,*prev;
    for(int i=0;i<k;i++)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;

    return A;
}
