#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

class solution{
    public:
    Node* startPoint(Node* head){

        //Brute-Force Approach
        // unordered_set<Node*> visited;
        // while (head!=NULL)
        // {
        //     if (visited.find(head)!=visited.end())
        //     {
        //         return head;
        //     }
        //     visited.insert(head);
        //     head=head->next;
        // }
        // return NULL;

        //Optimal Approach

        Node* slow=head;
        Node* fast=head;
        while (fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
        return NULL;
    }
};

int main(){
  Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);

    head->next->next->next->next = head->next;

    solution obj;
    Node* startNode = obj.startPoint(head);

    if(startNode)
        cout<<"Cycle starts at node with value: "<<startNode->data<<endl;
    else
        cout<<"No cycle found."<<endl;
    return 0;
}