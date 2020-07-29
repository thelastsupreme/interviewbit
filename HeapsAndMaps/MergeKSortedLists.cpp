#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode *mergeKLists(vector<ListNode *> &A)
{
    ListNode *ans = NULL;
    priority_queue<int, vector<int>, greater<int>> qu;
    for (int i = 0; i < A.size(); i++)
    {
        ListNode *temp = A[i];
        while (temp != NULL)
        {
            qu.push(temp->val);
            temp = temp->next;
        }
    }
    ans = new ListNode(qu.top());
    qu.pop();
    ListNode *ptr = ans;
    while (!qu.empty())
    {
        ListNode *temp = new ListNode(qu.top());
        qu.pop();
        ptr->next = temp;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return ans;
}
