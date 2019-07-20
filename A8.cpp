#include<bits/stdc++.h>
using namespace std;
struct node
{
	node *l,*r;
	string word;
	string mean;
	int height;
};
class q
{
	public:  
			node *root;
			q() {	root=NULL;	}

			int max(int a,int b);
			int height(node *n);
			int getbalance(node *n);

			node *newnode(string x,string y);
			void create();
			node *insert(node *n,string x,string y);

			node *ll(node *y);
			node *rr(node *y);
			void preorder(node *root);
};
int q::max(int a,int b)
{
	return (a>b?a:b);
}
int q::height(node*n)
{
	if(n==NULL)
	return 0;
	else
	return n->height;
}
int q::getbalance(node *n)
{
	if(n==NULL)
	return 0;
	return height(n->l)-height(n->r);
}
void q::create()
{
	string x,y;
	int k;
	do
	{
		cout<<"\n ENTER WORD : ";cin>>x;
		cout<<"\n ENTER MEANING : ";cin>>y;
		root=insert(root,x,y);
		cout<<"\n PRESS 0 TO STOP ADDING ";cin>>k;
	}while(k!=0);
}

node *q::newnode(string x,string y)
{
   node * nn=new node ;
	nn->word=x;
	nn->mean=y;
	nn->l=NULL;
	nn->r=NULL;
	nn->height=1;
	
	return nn;
}
node *q::insert(node *root,string x,string y)
{
	if(root==NULL) 
		return (newnode(x,y));
		
		if(x<root->word) 
			root->l=insert(root->l,x,y); 
			
		else if(x>root->word) 
			root->r=insert(root->r,x,y); 
			
		else
		return root;
		
		root->height=max(	height(root->l),height(root->r)	)+1;
		
		int balance=getbalance(root);
		
		if(balance>1 && x<root->l->word)
		return rr(root);
	 
	 	if(balance<-1 && x>root->r->word)
	 	return ll(root);
	 	
	 	if(balance>1 && x>root->l->word)
	 	{	
	 		root->l=ll(root);
	 		return rr(root);
	 	}
	 	if(balance<-1 && x<root->r->word)
	 	{
	 		root->r=rr(root);
	 		return ll(root);
	 	}
	 	
	 	
	 	return root;
}
node * q:: ll(node *x)
{
	node *xr=x->r;
	node *xrl=xr->l;
	
	xr->l=x;
	x->r=xrl;
	
	
	x->height = max(height(x->l),
			height(x->r)) + 1;
	xr->height = max(height(xr->l),
			height(xr->r)) + 1;
			
			return xr;
}
node * q:: rr(node *x)
{
	node *xl=x->l;
	node *xlr=xl->r;
	
	xl->r=x;
	x->l=xlr;
	
	
	x->height = max(height(x->l),
			height(x->r)) + 1;
	xl->height = max(height(xl->l),
			height(xl->r)) + 1;
			
			return xl;
}
void q::preorder(node *root)
{
	if(root != NULL)
	{
		cout << root->word << " ";
		preorder(root->l);
		preorder(root->r);
	}
}


int main()
{
	q t;
	t.create();
	cout<<endl;
	cout << "Preorder traversal of the "
			"constructed AVL tree is : \n";
	t.preorder(t.root);

	return 0;
}
















