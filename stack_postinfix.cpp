#include <bits/stdc++.h>
using namespace std;
int n=100;
char stackk[100];
int top=-1;
void push(char val) {
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
      //cout<</*"The popped element is "<<*/ stackk[top] <<endl;
      top--;
   }
}
char topp()
{
   //cout<<stackk[top]<<endl;
   return stackk[top];
}
void display() {
   if(top>=0) {
      //cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stackk[i]<<" ";
      //cout<<"fghjk"<<endl;
   } else
   cout<<"Stack is empty";
}
int main() {
   int a,b,c;
   string str;
   cin>>str;
   char ch;
   a=str.size();
   //cout<<str;
   //cout<<a<<endl;
   map<char,int>m={{'+',1},{'-',1},{'*',2},{'/',2},{'(',-3},{')',3}};
   for(int i=0;i<a;i++)
   {
      if(str[i]>='A' && str[i]<='Z')
      {
         cout<<str[i];
      }
      else if(str[i]=='(')
      {
         push(str[i]);
      }
      else if(str[i]==')')
      {
         //cout<<topp()<<"dgd"<<endl;
         while(1)
         {
            if(topp()=='(')
            {
               pop();
               break;
            }
            else
            {
               cout<<topp();
               //display();
               //cout<<topp()<<"*";
               pop();
            }
         }
         topp();
      }
      else if(str[i]=='+' || str[i]=='-' ||str[i]=='*' || str[i]=='/')
      {
         if(m[topp()]>m[str[i]])
         {
            cout<<topp();
            pop();
            push(str[i]);
         }
         else
         {
            push(str[i]);
         }
      }
   } 
   cout<<endl;
   /*topp();
   pop();
   display();
   topp();*/
   return 0;
}