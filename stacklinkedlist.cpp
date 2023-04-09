#include <bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	Node* link;
	Node(int n)
	{
		this->data = n;
		this->link = NULL;
	}
};
class Stack {
public:
	Node* top;
	Stack()
	{ 
		top = NULL;
	}
	void push(int data)
	{

		Node* temp = new Node(data);
		if (!temp) {
			cout << "\nStack Overflow";
			exit(1);
		}
		temp->data = data;
		temp->link = top;
		top = temp;
		//cout<<top<<endl;
	}
	bool isEmpty()
	{
		return top == NULL;
	}
	int peek()
	{
		if (!isEmpty())
			return top->data;
		else
			exit(1);
	}
	void pop()
	{
		Node* temp;
		if (top == NULL) {
			cout << "\nStack Underflow" << endl;
			exit(1);
		}
		else {
			temp = top;
			top = top->link;
			free(temp);
		}
	}
	void display()
	{
		Node* temp;
		if (top == NULL) {
			cout << "\nStack Underflow";
			exit(1);
		}
		else {
			temp = top;
			while (temp != NULL) {
				cout << temp->data;
				temp = temp->link;
				if (temp != NULL)
					cout << " -> ";
			}
		}
	}
};
int main()
{
	Stack s;
	int a,b;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b;
		s.push(b);
	}
	s.pop();
	s.display();
	return 0;
}
