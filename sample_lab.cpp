#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* reverse(Node* head, int k){
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
    while(current!=NULL && count<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if(next!=NULL){
        head->next = reverse(next, k);

    }
    return prev;
}

void push(Node** head_ref)
{
    int data;
    cout<<"enter the data:\n";
    cin>>data;
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* node)
{
    while (node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

int main()
{

    Node* head = NULL;
    int k, n;
    cout<<"Enter number of elements in linked list:\n";
    cin>>n;
    cout<<"Enter reverse sub list size:\n";
    cin>>k;
    for(int i=0; i<n; i++){
        push(&head);
    }


    cout<<"Given linked list \n";
    printList(head);
    head = reverse(head, k);

    cout<<"\nReversed Linked list \n";
    printList(head);

    return(0);
}