//single
#include<bits/stdc++.h>
using namespace std;
class Node{
     public:
     int data;
     Node* next; 

     Node(int data)
     {
     	this -> data = data;
     	this -> next = NULL;

     }
     ~Node()
     {
     	int value =this->data;
     	if(this->next !=NULL)
     	{
     		delete next;
     		this->next =NULL;
     	}
     	cout<<" memory is free for node with data " <<value<<endl;
     }
};
void InsertNode(Node* &tail,int element,int d)
{
     if(tail==NULL)
     {
          Node* newNode=new Node(d);
          tail= newNode;
          newNode->next=newNode;
     }
     else
     {
          Node* curr=tail;
          while(curr->data!=element)
          {
               curr=curr->next;
          }
          Node* temp=new Node(d);
          temp->next=curr->next;
          curr->next=temp;
     }
}
void deleteNode(Node* &tail,int value)
{
     //cout<<tail->data<<endl;
     if(tail==NULL)
     {
          return;
     }
     else
     {
          Node* prev=tail;
          Node* curr=prev->next;
          while(curr->data !=value)
          {
               prev=curr;
               curr=curr->next;
          }
          prev->next=curr->next;
          curr->next=NULL;
          delete curr;
     }
}
void print(Node* &tail)
{
     Node* temp=tail;
     do{
          cout<<tail->data<<" ";
          tail=tail->next;
     }while(tail!=temp);
     cout<<endl;    
}
int main()
{
     Node* tail=NULL;
     InsertNode(tail,5,3);
     print(tail);
     InsertNode(tail,3,7);
     print(tail);
     InsertNode(tail,3,3);
     print(tail);
     InsertNode(tail,3,7);
     print(tail);
     deleteNode(tail,7);
     print(tail);
}