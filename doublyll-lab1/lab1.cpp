#include <bits/stdc++.h>
#include<inttypes.h>
using namespace std;

class node
{
 public:
 int data;
 node *npx;
};

node *XOR (node *a,node *b)
{
  return (node*)((uintptr_t) (a) ^  (uintptr_t) (b));
}

void insert(node **head,int key)
{
 node *new_node=new node();
 new_node->data=key;
 new_node->npx=*head;
 if(*head!=NULL)
 {
 (*head)->npx=XOR(new_node,(*head)->npx);
 }
*head=new_node;
}

node *deleteb(node *head)
{
 if(head == NULL)
  return NULL;
 node *temp=XOR(head->npx,NULL);
 temp->npx=XOR(head,temp->npx);
 free(head);
 return temp;

}
void print(node *head)
{
 node *curr=head;
 node *prev=NULL;
 node *next;
 cout<<"The Linked List as follows: "<<endl;
 while(curr!=NULL)
 {
  cout<<curr->data<<" ";
 next=XOR(prev,curr->npx);
 prev=curr;
 curr=next;
 }
}

void insertend(node **head,int data)
{
  node *new_node=new node();
  new_node->data=data;
  if(*head==NULL)
  {
   new_node->npx=*head;
   *head=new_node;
   }
  else
  {
 node *curr=*head;
 node *prev=NULL;
 node *next;
 while(XOR(prev,curr->npx)!=NULL)
 {
  next=XOR(prev,curr->npx);
  prev=curr;
  curr=next;
 }
 new_node->npx=curr;
 curr->npx=XOR(prev,new_node);
 }
}

node *deleteend(node *head)
{
  node *curr=head;
  node *prev=NULL;
  node *next=XOR(curr->npx,prev);
  if(head == NULL)
   return NULL;
   
   while(next!=NULL)
   {
    prev=curr;
    curr=next;
    next=XOR(curr->npx,prev);
   }
   if(prev!=NULL)
   prev->npx=XOR(prev->npx,curr);
    
    free(curr);
    return head;
}
  
  
int main()
{
 
 node *head=NULL;
 cout<<"Inserting from the end"<<endl;
 insertend(&head,1);
 insertend(&head,2);
 insertend(&head,3);
 
 print(head);
 cout<<endl;
 cout<<"Inserting from the Begining"<<endl;
  insert(&head,4);
 insert(&head,5);
 insert(&head,6);
 print(head);
 
 cout<<endl;
 cout<<"Deletion from the begining"<<endl;
 head=deleteb(head);
 print(head);
 cout<<endl;
 cout<<"Deletion in the end"<<endl;
 head=deleteend(head);
 print(head);
 
 
 return 0;
}
