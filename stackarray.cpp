#include <bits/stdc++.h>
using namespace std;
int n=100;
int stackk[100];
int top=-1;
void push(int val) {
   if(top>=n-1)
   cout<<"Stack Overflow"<<endl;
   else {
      top++;
      stackk[top]=val;
   }
}
void pop() {
   if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< stackk[top] <<endl;
      top--;
   }
}
void topp()
{
   cout<<stackk[top]<<endl;
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stackk[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
int main() {
   int a,b,c;
   cin>>a;
   for(int i=0;i<a;i++)
   {
      cin>>b;
      push(b);
   } 
   display();
   topp();
   pop();
   display();
   topp();
   return 0;
}