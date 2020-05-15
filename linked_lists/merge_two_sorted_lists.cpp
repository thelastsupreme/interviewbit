//prabhaths && krutikas code
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *res= new ListNode(0);
    ListNode *temp=res;
    ListNode *tempa=A;
    ListNode *tempb=B;
    while(tempa!=NULL&&tempb!=NULL)
    {
        if(tempa->val<=tempb->val)
        {
            temp->next=tempa;
            tempa=tempa->next;
        }
        else
        {
            temp->next=tempb;
            tempb=tempb->next;
        }
        temp=temp->next;

    }
    while(tempa!=NULL)
    {
       temp->next=tempa;
       tempa=tempa->next;
       temp=temp->next;
    }
    while(tempb!=NULL)
    {
       temp->next=tempb;
       tempb=tempb->next;
       temp=temp->next;
    }
    return res->next;
}

//recursive approach
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return(b);
    else if (b == NULL)
        return(a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}
