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
void InsertAtHead(Node* &head, int d)
{
	Node* temp=new Node(d);
	temp->next=head;
	head=temp;
}
void InsertAtTail(Node* &tail, int d)
{
	Node* temp=new Node(d);
	tail->next=temp;
	tail=temp;
}
void InsertAtPosition(Node* &tail,Node* &head,int position, int d)
{
	if(position==1)
	{
		InsertAtHead(head,d);
		return;
	}
	Node* temp=head;
	int cnt=1;
	while(cnt< position-1)
	{
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL) 
	{
		InsertAtTail(tail,d);
		return;
	}
	Node* NodeToInsert=new Node(d);
	NodeToInsert-> next =temp->next;
	temp->next=NodeToInsert;
}
void deleteNode(int position,Node* &head)
{
	if(position==1)
	{
		Node* temp=head;
		head =head->next;
		//cout<<temp<<endl;
		temp->next=NULL;
		//delete temp;
	}
	else
	{
		Node* curr=head;
		Node* prev=NULL;

		int cnt=1;
		while(cnt< position)
		{
			prev=curr;
			curr=curr->next;
			cnt++;
		}
		prev -> next =curr->next;
		curr->next=NULL;
		//delete curr;
	}
}
void print(Node* &head)
{
	//cout<<head<<endl;
	Node* temp=head;
	while(temp !=NULL)
	{
		cout<<temp->data<<" ";
		temp= temp->next;
	}
	cout<<endl;
}
int main()
{
	Node* node1=new Node(10);
	//cout<<node1->data <<endl;
	//cout<<node1->next <<endl;
	Node* head=node1;
	Node* tail=node1;
	InsertAtTail(tail,55);
	print(head);
	InsertAtHead(head,12);
	print(head);
	InsertAtHead(head,15);
	print(head);
	InsertAtHead(head,35);
	print(head);
	InsertAtTail(tail,55);
	print(head);
	InsertAtTail(tail,95);
	print(head);
	InsertAtPosition(tail,head,7, 22);
	print(head);
	deleteNode(5,head);
	print(head);
}