//prabhaths code
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
int Solution::lPalin(ListNode* A) {
    ListNode* temp=A;
   // ListNode* temp1=A;
    int len=length(A);
    stack<int>s;
    for(int i=0;i<len;i++)
    {
        if(i<len/2)
        {
            s.push(temp->val);
        }
        else if(i==len/2 && len%2==1)
        {
            temp=temp->next;
            continue;
        }
        else
        {
            if(!s.empty()&&s.top()==temp->val)
                s.pop();
            else
                return 0;
        }
        temp=temp->next;
    }
    return 1;

}
//best approach
int recur(ListNode*& head, ListNode* tail) {
    if (!tail) return 1;
    int val = recur(head, tail->next) && head->val == tail->val;
    head = head->next;
    return val;
}

int Solution::lPalin(ListNode* A) {
    return recur(A, A);
}
