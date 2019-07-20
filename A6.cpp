//============================================================================
// Name        : symbol.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#include<iomanip>
using namespace std;
struct node
{
	string name,type;
	int count,value;
	int line_no[10];
	node *next;
};
class q
{
private : node *head;
		  node *nn;
public:	void insert();
		void display();
		void search();
		void modify();
		void del();
		q() {  head=NULL;}

};
void q::insert()
{
	nn=new node;

	cout<<"\n ENTER DETAILS ";

	cout<<"\n Enter name : ";
	cin>>nn->name;
	cout<<"\n Enter type : ";
    cin>>nn->type;
	 cout<<"\n Enter  initial value : ";
	 cin>>nn->value;
	 cout<<"\n Enter  count : ";
	 cin>>nn->count;
 	 cout<<"\n Enter line no. ";
	 for(int i=0;i<nn->count;i++)
	 {
		 cout<<"\n line : ";
		 cin>>nn->line_no[i];
		 
	 }
	 nn->next=NULL;

	 if(head==NULL)
	 {
		  head=nn;
	 }
	 else
	 {
		 node *cn;
		 cn=head;
		 while(cn->next!=NULL)
			 cn=cn->next;
		 cn->next=nn;
	 }
}
void q::display()
{
	int k=1;
	node *cn;
	cn=head;
	cout<<"________________________________________________________________________"<<endl;
	cout<<endl;
	cout<<"Sr no. "<<"\t";
	cout<<"NAME"<<"\t";
    cout<<"TYPE"<<"\t";
	cout<<"VALUE"<<"\t";
	cout<<"COUNT"<<"\t";
	cout<<"LINE NUMBER"<<"\t";
	cout<<endl; 
	cout<<"________________________________________________________________________";
	cout<<endl;
	while(cn!=NULL)
	{
		cout<<k<<".\t";k++;
		cout<<cn->name<<"\t";
		cout<<cn->type<<"\t";
		cout<<cn->value<<"\t";
		cout<<cn->count<<"\t";
		for(int i=0;i<cn->count;i++)
			 {
				 cout<<cn->line_no[i]<<" ";
				 if(i!=nn->count-1)
				 cout<<", ";
			 }
		cn=cn->next;
		cout<<"\n----------------------------------------------------------------------"<<endl;
		cout<<endl;
	}
	cout<<"________________________________________________________________________";
}
void q::search()
{
	string temp;
	int flag=0;
	cout<<"\n Enter name of identifier that you want to search: ";
	cin>>temp;
	node *cn;
	cn=head;
	while(cn!=NULL)
	{
		if(cn->name==temp)
		{
			cout<<"FOUND :"<<endl;
			cout<<"Name: "<<cn->name<<"\t";
		    cout<<"Type: "<<cn->type<<"\t";
		     cout<<"Value: "<<cn->value<<"\t";
		     cout<<"Count: "<<cn->count<<"\t";
		     flag=1;
		     break;
		}
		cn=cn->next;
	}
	if(flag==0)
		cout<<"\nDATA ENTRY NOT FOUND ";
}
void q::modify()
{
	string temp;
		int flag=0;
		cout<<"\n Enter name of identifier that you want to modify: ";
		cin>>temp;
		node *cn;
		cn=head;
		while(cn!=NULL)
			{
				if(cn->name==temp)
				{
					cout<<"Enter modifications: "<<endl;
					int n;
					do
					{
						cout<<"\n CHOOSE THE FIELD YOU WANT TO MODIFY ";
						cout<<"\n1.NAME";
						cout<<"\n2.TYPE";
						cout<<"\n3.VALUE ";
						cout<<"\n4.COUNT ";
						cout<<"\nYOUR OPTION : ";
						cin>>n;
						switch(n)
						{
						case 1: cout<<"Name: "; cin>>cn->name;break;
						case 2: cout<<"Type: "; cin>>cn->type ;break;
						case 3: cout<<"Value: ";cin>>cn->value ;break;
						case 4: cout<<"Count: ";cin>>cn->count ;break;
						case 0:break;
						}
					}while(n!=0);
				     flag=1;
				     break;
				}
				cn=cn->next;
			}
		if(flag==0)
				cout<<"\nDATA ENTRY NOT FOUND ";
}
void q::del()
{
	string temp;
	int flag=0;
	 cout<<"\n Enter name of identifier that you want to delete: ";
	 cin>>temp;
	 node *cn,*pre;
	 cn=head;
	 pre=head;
	 while(cn!=NULL)
	 {
		 if(cn->name==temp)
		 {
			 pre->next=cn->next;
			 delete cn;
		 }
		 pre=cn;
		 cn=cn->next;
		 flag=1;
		 break;
	 }
	 if(flag==0)
	  cout<<"\nDATA ENTRY NOT FOUND ";

}
int main()
{
	q w;
	int n;
	do
	{
	cout<<"\n ***********SYMBOL TABLE OPERATIONS***********";
	cout<<std::setw(25)<<"\n1.Insert";
	cout<<"\n2.Display";
	cout<<"\n3.Search";
	cout<<"\n4.Modify";
	cout<<"\n5.Delete";
	cout<<"\n0.EXIT";
	cout<<"\nYOUR OPTION : ";
	cin>>n;
	switch(n)
	{
		case 1:w.insert();break;
		case 2:w.display();break;
		case 3:w.search();break;
		case 4:w.modify();break;
		case 5:w.del();break;
		case 0:break;
	}

	}while(n!=0);
}
