#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
        data=data1;
        back=back1;
        next=next1;
    }
    
    Node(int data1){
        data=data1;
        back=nullptr;
        next=nullptr;
    }
};

Node* convertArr2DLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

void print(Node* head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }  
}

//-----------Brute Force Approach-------------

// Node* reverseDLL(Node* head){
//     if (head==nullptr || head->next==nullptr)
//     {
//         return head;
//     }
//     stack<int> st;
//     Node* temp = head;
//     while (temp!=nullptr)
//     {
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while (temp!=nullptr)
//     {
//         temp->data=st.top();
//         st.pop();
//         temp=temp->next;
//     }
//     return head;
// }

//--------------Optimal Approach--------------

Node* reverseDLL(Node* head){
    if (head==nullptr || head->next==nullptr)
    {
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    while (current!=nullptr)
    {
       Node* temp=current->next;
       current->next=current->back;
       current->back=temp;
       head=current;
       current=temp;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArr2DLL(arr);
    head = reverseDLL(head);
    print(head);
    
    return 0;
}