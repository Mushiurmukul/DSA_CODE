x#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		Node(int data)
		{
			this->data=data;
			this->prev=NULL;
			this->next=NULL;
		}
};
void InsertAtFirst(Node* &head,int d)
{
	Node* temp=new Node(d);
	head->prev=temp;
	temp->next=head;
	head=temp;
}
void InsertAtLast(Node* &tail,int d)
{
	Node* temp=new Node(d);
	temp->prev=tail;
	tail->next=temp;
	tail=temp;
}
void InsertAtMiddle(Node* &head,Node* &tail,int d,int position)
{
	Node* temp=head;
	int cnt=1;
	if(position==1)
	{
		InsertAtFirst(head,d);
		return;
	}
	while(cnt<position-1)
	{
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL)
	{
		InsertAtLast(tail,d);
		return;
	}
	Node* element =new Node(d);
	element->next=temp->next;
	element->prev=temp;
	temp->next=element;
}
void delet(Node* &head,int position)
{
	if(position ==1)
	{
		Node* temp=head;
		head =head->next;
		temp->next=NULL;
		head->prev=NULL;
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
		curr ->prev=NULL;
		prev -> next =curr->next;
		curr->next=NULL;
		//delete curr;
	}
}
void show(Node* &head)
{
	Node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int len(Node* &head)
{
	Node* temp=head;
	int len=0;
	while(temp!=NULL)
	{
		len++;
		temp=temp->next;
	}
	return len;
}
int main()
{
	Node* node1=new Node(10);
	Node* head=node1;
	Node* tail=node1;
	show(head);
	cout<<len(head)<<endl;
	InsertAtFirst(head,16);
	show(head);
	cout<<len(head)<<endl;
	InsertAtLast(tail,67);
	show(head);
	cout<<len(head)<<endl;
	InsertAtMiddle(head,tail,89,4);
	show(head);
	cout<<len(head)<<endl;
	delet(head,4);
	show(head);
	cout<<len(head)<<endl;
}