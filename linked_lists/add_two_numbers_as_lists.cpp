ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* res= new ListNode(0);
    ListNode* temp1=res;
    int sum=0,carry=0;
    ListNode* tempa=A;
    ListNode* tempb=B;
    while(tempa!=NULL&&tempb!=NULL)
    {
        int sum=tempa->val+tempb->val+carry;
        if(sum>9)
        {
            carry=1;
            sum=sum-10;
        }
        else
            carry=0;
        ListNode* temp=new ListNode(sum);
        temp1->next=temp;
        temp1=temp1->next;
        tempa=tempa->next;
        tempb=tempb->next;

    }
    while(tempa!=NULL)
    {
        sum=tempa->val+carry;
        if(sum>9)
        {
            carry=1;
            sum-=10;
        }
        else
            carry=0;
        ListNode* temp=new ListNode(sum);
        temp1->next=temp;
        temp1=temp1->next;
        tempa=tempa->next;
    }
    while(tempb!=NULL)
    {
        sum=tempb->val+carry;
        if(sum>9)
        {
            carry=1;
            sum-=10;
        }
        else
            carry=0;
        ListNode* temp=new ListNode(sum);
        temp1->next=temp;
        temp1=temp1->next;
        tempb=tempb->next;
    }
    if(carry==1)
    {
        ListNode *temp =new ListNode(1);
        temp1->next=temp;
    }
    return res->next;
}
