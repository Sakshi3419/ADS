#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class q
{
	private: int v,e;
		node *nn,*nn1;
		int 	a[10][10];
		int visited[10];
			 
	public:
			 void g();
			 void matrix();
			 void list(); 
			 void dfs(int a);
			 void bfs();
			 
			 q()
			 {
			 	for(int i=0;i<10;i++)
			 	visited[i]=0;
			 }

};
void q::g()
{
	cout<<"\nENTER NUMBER OF VERTICES: ";
	cin>>v;
	cout<<"\nENTER NUMBER OF EDGES:  ";
	cin>>e;
	 
}
void q::matrix()
{
	
	int	n=1,x,y;
	for(int i=0;i<v;i++)
	for(int j=0;j<v;j++)
	a[i][j]=0;
	for(int i=0;i<e;i++)
	{
	cout<<"ENTER VERTICES THAT HAVE EDGES AMONG THEM (X-Y)";
	cin>>x>>y;
	a[x][y]=1;
	a[y][x]=1;
	}
	 
	
	cout<<"\n MATRIX REPRESENTATION OF GRAPH IS "<<endl;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<""<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	  
}
void q::list()
{
	 node *array[v];
	 for(int i=0;i<v;i++)
	 {
	 	array[i]=NULL;
	 }
	 int x,y;
	 for(int i=0;i<e;i++)
	 {
		 cout<<"ENTER VERTICES THAT HAVE EDGES AMONG THEM (X-Y)";
		 cin>>x>>y;
		 nn=new node;
		 nn->data=x;
		 nn->next=NULL;
		 node *cn;
		 cn=array[y];
		 if(array[y]==NULL)
		 array[y]=nn;
		 else
		 {
		 	while(cn->next!=NULL)
		 	cn=cn->next;
		 	cn->next=nn;
		 }
		  nn1=new node;
		 nn1->data=y;
		 nn1->next=NULL;
		 node *cn1;
		 cn1=array[x];
		 if(array[x]==NULL)
		 array[x]=nn1;
		 else
		 {
		 	while(cn1->next!=NULL)
		 	cn1=cn1->next;
		 	cn1->next=nn1;
		 }
		  
		  
	 }  
	 cout<<"\n LIST REPRESENTATION IS "<<endl;
	 for(int i=0;i<e;i++)
	 {
		 cout<<"FOR VERTEX "<<i<<" : " ;
		 node *t;
		 t=array[i];
		 
		 while(t!=NULL)
		 {
		 	cout<<t->data<<" ";
		 	t=t->next;
		 }
		 
		 cout<<endl;
	 }
	 
	  
}
void q::dfs(int i)
{
	int j;
	visited[i]=1;
	cout<<i;
	for(int j=0;j<v;j++)
	if(visited[i]!=0 && a[i][j]==1)
	dfs(j);
}
int main()
{
	q w;
	int n;
	do
	{
		cout<<"\n CHOOSE THE OPERATION YOU WISH TO PERFORM ";
		cout<<"\n1.ENTER DATA ";
		cout<<"\n2.MATRIX ERPRESENTATION ";
		cout<<"\n3.LIST REPRESENTATION ";
		cout<<"\n4.DFS RECCURSIVE ";
		cout<<"\n0.TO EXIT ";
		cin>>n;
		switch(n)
		{
			case 1:w.g();break;
			case 2:w.matrix();break;
			case 3:w.list();break;
			case 4:w.dfs(0);break;
			case 0:break;
			default: cout<<"ENTER VALID OPTION ";
			
		}
	}while(n!=0);
	
	
	
}
















