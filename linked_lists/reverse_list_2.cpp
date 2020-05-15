//prakritis code
ListNode* reverse( ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C)
{
    if(B==C)
        return A;
    ListNode *temp=A,*first=A,*last=A;
    ListNode *prev=NULL;
    int i=1;

    for(i;i<B;i++)
    {
     prev=temp;
     temp=temp->next;
    }
   first=temp;

    for(i;i<C;i++)
    {
     temp=temp->next;
    }
    last=temp;

    ListNode* next=last->next;
    last->next=NULL;

    first=reverse(first);

    if(prev!=NULL)
        prev->next=first;
    else
        A=first;
    temp=first;

    while(temp->next!=NULL)
     temp=temp->next;

    temp->next=next;
    return A;
}
//prabhaths code
int length (ListNode *head)
{
    ListNode *cur=head;
    int count=0;
    for(cur=head;cur!=NULL;cur=cur->next)
    {
        count++;
    }
    return count;
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B==C)
        return A;
    int len=length(A);
    vector<int>v;
    for(int i=0;i<len;i++)
    {
        v.push_back(A->val);
        A=A->next;
    }
    reverse(v.begin()+B-1,v.begin()+C);
    ListNode* res=new ListNode(0);
    ListNode* t=res->next;
    for(int i=0;i<v.size();i++)
    {
        t->val=v[i];
        t=t->next;
    }
    return res->next;
}
