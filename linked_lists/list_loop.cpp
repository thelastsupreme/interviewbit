//prabhaths code
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* fast=A;
    ListNode* slow=A;
    bool flag=0;

    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            flag=1;
            break;
        }
    }
    if(!flag)
        return NULL;
    if(flag)
    {
        ListNode* res=A;
        while(res!=slow)
        {
            res=res->next;
            slow=slow->next;
        }
        return res;
    }

}
