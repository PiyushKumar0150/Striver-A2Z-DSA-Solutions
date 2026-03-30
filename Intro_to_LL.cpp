#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node* next;

    public:
    node(int data1, node* next1){
        data=data1;
        next=next1;
    }

    public:
    node(int data1){
        data=data1;
        next=nullptr;
    }
};

    node* convertarr2LL(vector<int>& arr){
        node* head = new node{arr[0]};
        node* mover = head;
        for (int i = 1; i < arr.size(); i++)
        {
            node* temp = new node{arr[i]};
            mover->next=temp;
            mover=temp;
        }
        return head;
    }

    int lengthofLL(node* head){
        int cnt=0;
        node* temp=head;
    while (temp)
    {
       temp=temp->next;
        cnt++;
    }
    return cnt;
    }

    int checkIfPresent(node* head, int val){
        node* temp = head;
        while (temp)
        {
            if (temp->data==val)
            {
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }

int main(){
    vector<int> arr={2,4,7,8};
    node* y = new node{arr[0], nullptr};
    // cout<<y->data;
    // cout<<y->next;
    // cout<<y;

    // node z = node{arr[0],nullptr};
    // cout<<z.data;
    // cout<<z.next;

    // node* x = new node{arr[0]};
    // cout<<x->next;

    node* head = convertarr2LL(arr);
    //cout<<head->data;
    // node* temp=head;
    // while (temp)
    // {
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }

    // cout<<lengthofLL(head);
    //cout<<checkIfPresent(head, 4);
    cout<<checkIfPresent(head, 5);
    
    return 0;
}