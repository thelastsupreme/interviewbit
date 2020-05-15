
//krutikas code
ListNode* Solution::reverseList(ListNode* A) {

    ListNode *prev=NULL;
    ListNode *temp=A;
    ListNode *nxt;
    if(A->next==NULL)
       return A;
    nxt=temp->next;
    while(temp->next!=NULL)
    {
        nxt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt;
    }
    temp->next=prev;
    A=temp;
    return A;
}

//general code
ListNode* Solution::reverseList(ListNode* A) {
    ListNode *curr,*prev,*next;
    curr=A;
    prev=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    A=prev;
    return A;

}
//recursive code prakritis
Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node* rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return rest;
    }

//using two pointers xor
void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;

    // at last prev points to new head
    while (current != NULL) {
        // This expression evaluates from left to right
        // current->next = prev, changes the link fron
        // next to prev node
        // prev = current, moves prev to current node for
        // next reversal of node
        // This example of list will clear it more 1->2->3->4
        // initially prev = 1, current = 2
        // Final expression will be current = 1^2^3^2^1,
        // as we know that bitwise XOR of two same
        // numbers will always be 0 i.e; 1^1 = 2^2 = 0
        // After the evaluation of expression current = 3 that
        // means it has been moved by one node from its
        // previous position
        current = (struct Node*)((ut)prev ^ (ut)current ^ (ut)(current->next) ^ (ut)(current->next = prev) ^ (ut)(prev = current));
    }

    *head_ref = prev;
}
//stackoverflow code reverse using two pointers

Node* reverse(Node* root) {
  Node* new_root = 0;
  while (root) {
    Node* next = root->next;
    root->next = new_root;
    new_root = root;
    root = next;
  }
  return new_root;
}

Node * reverse(Node *cur) {
    Node *prev = NULL;
    while (cur) {
        Node *temp = cur;
        cur = cur->next; // advance cur
        temp->next = prev;
        prev = temp; // advance prev
    }
    return prev;
}
//
