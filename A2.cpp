#include<iostream>
#include<string.h>
using namespace std;
struct node
{
	char data;
	node *l ;
	node *r ;
};
class stack
{
	public:
			node *a[20];
			void push(node*);
			node* pop();
			node* return_top();
			int top;
			int isempty();
			stack() {	top=-1;	}		
};
node* stack:: return_top()
{
	return a[top];
}
int stack::isempty()
{
	if(top==-1) return 1;
	return 0;
}
void stack::push(node *temp)
{
	top++;
	a[top]=temp; 
}
node* stack::pop()
{ 
	top--; 
}
class q :public stack
{
	private:	stack operator_s ;
			stack operand_s ;
			char exp[20];
			node *root;
	public:
		node *nn;
		void g();
		void c();
		void pre(node *);
		void in(node *);
		void post(node *);
		int p(char a);
};
void q::g()
{
	cout<<"\n ENTER EXPRRESSION ";
	cin>>exp;
}
int q::p(char a)
{
	if(a=='*'||a=='/')
	return 2;
	if(a=='+'||a=='-')
	return 1;
	return 0;
}
void q::c()
{
	 
		node *temp;
	for(int i=0;exp[i]!='\0';i++)
	{
		nn=new node;
		nn->data=exp[i];
		nn->l=nn->r=NULL;
		if(exp[i]=='*'||exp[i]=='+'||exp[i]=='-'||exp[i]=='/')
		{
			if(top!=-1)	
			{
					char x=operator_s.a[top]->data;
					int p1=p(x);
					int p2=p(nn->data);
					if(p(p1)>p(p2))
					{
						 
						temp=operator_s.return_top();
						operator_s.pop();
						temp->r=operand_s.return_top();
						operand_s.pop();
						temp->l=operand_s.return_top();
						operand_s.pop();
						operand_s.push(temp);
					}
					operator_s.push(nn);
					 
			}
				else
				operator_s.push(nn);
		}
		else
		operand_s.push(nn);
		 
	}
	node*temp1;
	while(operator_s.top!=-1)
	{
		
					temp1=operator_s.return_top();
						operator_s.pop();
						temp1->r=operand_s.return_top();
						operand_s.pop();
						temp1->l=operand_s.return_top();
						operand_s.pop();
						operand_s.push(temp1);
	}
	cout<<"\n PREORDER : ";
	pre(temp1);
	cout<<"\n POSTORDER : ";
	post(temp1);
	cout<<"\n INORDER : ";
	in(temp1);
	cout<<endl;
}
void q::pre(node* temp)
{	
	if(temp!=NULL)
	{
		cout<<temp->data<<" ";
		pre(temp->l);
		pre(temp->r);
	}
}
void q::post(node* temp)
{	
	if(temp!=NULL)
	{
		post(temp->l);
		post(temp->r);
		cout<<temp->data<<" ";
	}
}
void q::in(node* temp)
{	
	if(temp!=NULL)
	{
		in(temp->l);
		cout<<temp->data<<" ";
		in(temp->r);
	}
}
int main()
{
	q w;
	w.g();
	w.c();
	
}
