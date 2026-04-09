#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x): data(x),next(NULL){}
};

class solution{
    public:
    Node* reverseLL(Node* head){
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        Node* newHead = reverseLL(head->next);
        Node* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
};

void print(Node* head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    solution x;
    head = x.reverseLL(head);
    print(head);
    
    return 0;
}