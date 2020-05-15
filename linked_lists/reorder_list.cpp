//prabhaths code
ListNode* reverse(ListNode* mid)
{
    if(!mid || !mid->next)
        return mid;
    ListNode *curr, *next, *prev;
    prev = mid;
    curr = mid->next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    mid->next = curr;
    return prev;
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
ListNode* merge(ListNode* l1, ListNode* l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    ListNode* head = l1;
    l1 = l1->next;
    bool alteringListFlag = true;
    ListNode* p = head;
    while(l1 && l2)
    {
        if(!alteringListFlag)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        alteringListFlag = !alteringListFlag;
        p = p->next;
    }

    if(l1)
        p->next = l1;
    else
        p->next = l2;
    return head;
}

ListNode* Solution::reorderList(ListNode* A) {
    int len=length(A);
    if(len==1)
        return A;
    ListNode *slw = A, *fst = A;
    while(fst->next && fst->next->next)
    {
        slw = slw->next;
        fst = fst->next->next;
    }

    ListNode *mid = slw;
    ListNode* rev_p=reverse(mid);
    ListNode* ans=merge(A,rev_p);
    ListNode* prev=ans;
    for(int i=0;i<=len;i++)
    {
        prev=prev->next;
    }
    prev->next=NULL;
    return ans;
}
//krutikas code
ListNode* Solution::reorderList(ListNode* A) {

    stack<ListNode*> even;
    ListNode* temp1=new ListNode(0);
    ListNode* temp=A->next;
    while(temp!=NULL)
    {
        even.push(temp);
        temp=temp->next->next;
    }
    temp=A;
    while(temp!=NULL&&temp->next!=NULL&&temp->next->next!=NULL&&!even.empty()) //
    {
         temp1=even.top();
         temp1->next=temp->next->next;
         temp->next=temp1;
         even.pop();
         temp=temp->next->next;
    }
    temp->next=NULL;
    return A;
}
