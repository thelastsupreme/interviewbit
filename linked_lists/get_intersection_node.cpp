//prabhaths code
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
int len1=0, len2=0;
ListNode* temp = A;
    while( temp != NULL )
    {
        ++len1;
        temp = temp->next;
    }
    temp = B;
    while( temp != NULL )
    {
        ++len2;
        temp = temp->next;
    }
ListNode* temp1 = A;
ListNode* temp2 = B;
    if( len1>len2 )
    {
        len1 = len1-len2;
        while( len1>0 )
        {
            temp1 = temp1->next;
            --len1;
        }
    }
    else
    {
        len2 = len2-len1;
        while( len2>0 )
        {
            temp2 = temp2->next;
            --len2;
        }
    }
    while ( temp1 != temp2 )
    {
    temp1 = temp1->next;
    temp2 = temp2->next;
    }

if( temp1 != temp2 )
    return NULL;
return temp1;
}
