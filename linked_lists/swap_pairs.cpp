//prabhaths code
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *curr,*nxt;
    curr=A;
    while(curr!=NULL&&curr->next!=NULL)
    {
        nxt=curr->next;
        swap(nxt->val,curr->val);
        curr=nxt->next;
        nxt=curr->next;
    }
    return A;
}

//prakritis code
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode * res=A;
    ListNode * next;
    while(A!=NULL && A->next!=NULL)
    {
        next=A->next;
        swap(A->val,A->next->val);
        A=A->next->next;
    }
    return res;

}
//krutikas code
ListNode* Solution::swapPairs(ListNode* A) {

    int temp;
    ListNode* curr=A;
    ListNode* nxt=curr->next;
    while(curr!=NULL&&curr->next!=NULL) // PRAKRITI IS A GENIUS
    {
        nxt=curr->next;
        swap(curr->val,nxt->val);
        curr=nxt->next;
    }
    return A;
}
