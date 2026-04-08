#include<bits/stdc++.h>
using namespace std;

// struct Listnode{
//     int data;
//     Listnode* next;
//     Listnode(int x): data(x),next(NULL){}
// };

// class solution{
//     public:
//         Listnode* reverseLL(Listnode* head){
//         if (head==nullptr || head->next==nullptr)
//         {
//             return head;
//         }
//         stack<int> st;
//         Listnode* temp = head;
//         while (temp!=nullptr)
//         {
//             st.push(temp->data);
//             temp = temp->next;
//         }
//         temp = head;
//         while (temp!=nullptr)
//         {
//             temp->data = st.top();
//             st.pop();
//             temp=temp->next;
//         }
//         return head; 
//     }
// };

class Listnode{
    public:
    int data;
    Listnode* next;
    Listnode(int data){
        this->data=data;
        this->next=NULL;
    }
};

class solution{
    public:
    Listnode* reverseLL(Listnode* head){
        Listnode* prev = NULL;
        Listnode* temp = head;
        while (temp!=NULL)
        {
            Listnode* front = temp->next;
            temp->next=prev;
            prev=temp;
            temp =front;
        }
        return prev;
    }
};

void print(Listnode* head){
    while (head!= NULL)
    {
        cout<<head->data<<" ";
        head= head->next;
    } 
}

int main(){
    Listnode* head = new Listnode(1);
    head->next = new Listnode(2);
    head->next->next = new Listnode(3);
    head->next->next->next = new Listnode(4);
    head->next->next->next->next = new Listnode(5);
    head->next->next->next->next->next = new Listnode(6);

    solution x;
    head = x.reverseLL(head);
    print(head);
    
    return 0;
}