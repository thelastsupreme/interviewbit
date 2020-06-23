#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//basic Node template
struct Node
{
    int val;
    Node* next;
};
void print(Node* front)
{
    if(front==nullptr)
        cout<<"empty"<<endl;
    else
    {
        Node* curr=front;
        while(curr!=nullptr)
        {
            cout<<curr->val<<" -> ";
            curr=curr->next;
        }
    }
    cout<<"null"<<endl;
}

Node *vectorToLinkedList(vector<int>v)
{
    if(v.size()==0)
        return nullptr;
    Node *head=new Node{v[0] ,nullptr};
    Node *currptr=head;
    for(int i=1;i<v.size();i++)
    {
        Node *node=new Node{v[i],nullptr};
        currptr->next=node;
        currptr=node;
    }
    return head;
}

Node* insertionSort(Node* head){
    Node* curr=head;
    curr=curr->next;
    Node* temp=head;

    int t;
    while(curr!=nullptr){
        if(temp!=curr){
            if(temp->val>=curr->val){ //basic swap if val greater than the curr pointer
                t=curr->val;
                curr->val=temp->val;
                temp->val=t;
            }else{
                temp=temp->next;    //if in proper order just skip it
            }
        }else{
            curr=curr->next;  //if both temp and curr are equal go to next element
            temp=head;        //reset temp to head
        }
    }
    return head;
}

int main(){
    vector<int>A={2,5,3,1,6,4,7};
    Node* B=vectorToLinkedList(A);
    Node* result=insertionSort(B);
    print(result);
}

