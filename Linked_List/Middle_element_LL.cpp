#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x) : data(x),next(NULL){}
};

class solution{
    public:

    //Brute force approach(TC = O(N + N/2))
    // Node* middleLL(Node* head){
    //     if (head==NULL || head->next==NULL)
    //     {
    //         return head;
    //     }
    //     Node* temp=head;
    //     int count=0;
    //     while (temp!=NULL)
    //     {
    //         count++;
    //         temp=temp->next;
    //     }
    //     int mid = count/2 +1;
    //     temp = head;
    //     while (temp!= NULL)
    //     {
    //         mid=mid-1;
    //         if (mid==0)
    //         {
    //             break;
    //         }
    //         temp = temp->next;
    //     }
    //     return temp;
    // }

    //Optimal approach (Tortoise and Hare Algorithm)(TC = O(N/2))
    Node* middleLL(Node* head){
        Node* slow = head;
        Node* fast = head;
        while (fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    //head->next->next->next->next->next = new Node(6);

    solution x;
    Node* m = x.middleLL(head);
    cout<<m->data;
    
    return 0;
}