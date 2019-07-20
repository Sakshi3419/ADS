#include<iostream>
using namespace std;
struct node
{
    int data;
    node *l, *r;
    int lth, rth;
};
class tbt
{
    private: node *nn;
             node *root;
             
    public: node *dummy;
            tbt()
            { 
                root=NULL; 
                dummy=new node;
                dummy->lth=dummy->rth=0;
                dummy->l=dummy->r=NULL;
                dummy->data=-100;
             }
            void create();
            void indisplay();
            void predisplay();
};
void tbt::create()
{
    nn=new node;
    cout<<"\nenter data for the node: ";
    cin>>nn->data;
    nn->lth=nn->rth=0;
    nn->l=nn->r=NULL;
    if(root==NULL)
    {
        root=nn;
        dummy->l=root;
        root->l=root->r=dummy;
    }
    else
    {
        node *tmp, *par;
        tmp=root;
        while(tmp!=NULL)
        {
            par=tmp;
            if(nn->data < tmp->data)
            {
                if(tmp->lth == 1)
                    tmp=tmp->l;
                else
                    tmp=NULL;
            }        
            else
            {
                if(tmp->rth == 1)
                    tmp=tmp->r;
                else
                    tmp=NULL;
            }        
        }
        if(nn->data < par->data)
        {
            nn->l=par->l;
            nn->r=par;
            par->lth=1;
            par->l=nn;
        }
        else
        {
            nn->r=par->r;
            nn->l=par;
            par->rth=1;
            par->r=nn;
        }
    }
    
}
void tbt::indisplay()
{
    node *tmp;
    tmp=root;
    while(1)
    {
        while(tmp->lth==1)
            tmp=tmp->l;
        cout<<tmp->data<<"  ";
        while(tmp->rth==0)
        {
            if(tmp->r==dummy)
                return;
            else 
                tmp=tmp->r;
            cout<<tmp->data<<"  ";
        }
        tmp=tmp->r;              
    }
}
void tbt::predisplay()
{
    node *tmp;
    tmp=root;
    while(1)
    {
        while(tmp->lth==1)
        {
            cout<<tmp->data<<"  ";
            tmp=tmp->l;
        }
        cout<<tmp->data<<"  ";        
        while(tmp->rth==0)
        {
            if(tmp->r==dummy)
                return;
            else 
                tmp=tmp->r;
        }
        tmp=tmp->r;              
    }
}
int main()
{
    tbt q;
    int n;
    do
    {
    	cout<<"\nmenu:\n"
    		<<"1. create tree \n2. display inorder  \n3. display preorder\n\nenter choice: ";
    	cin>>n;
    	switch(n)
    	{
    		case 1: q.create();
    				break;
    		case 2: q.indisplay();
    				break;
    		case 3: q.predisplay();
    				break;

      	}

    }while(n!=0);
    
    return 0;
}
