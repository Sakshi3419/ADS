//============================================================================
// Name        : a.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

struct node
{
    node *l,*r;
    string word;
};
class tree
{
private: node *nn;
public: node *root;
    tree () { root=NULL;}
    void create();
    void pre(node *temp);
    void post(node *temp);
    void in(node *temp);
    void pre_nr(node *temp);
    void post_nr(node *temp);
    void in_nr(node *temp);
    void search();
    void update();
    void d();
};
void tree :: create ()
{
    nn=new node;
    cout<<"\n Enter word: ";
    cin>>nn->word;
    nn->l=nn->r=NULL;
    if(root==NULL)
        root=nn;
    else
    {
        node *temp,*parent;
        temp=root;
        while(temp!=NULL)
        {
            parent=temp;
            if(nn->word<temp->word)
                temp=temp->l;
            else
                temp=temp->r;
        }
        if(nn->word<parent->word)
               parent->l=nn;
         else
             parent->r=nn;
    }
}
void tree ::pre(node *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->word<<" ";
        pre(temp->l);
        pre(temp->r);
    }
}
void tree ::post(node *temp)
{
    if(temp!=NULL)
    {
        pre(temp->l);
        pre(temp->r);
        cout<<temp->word<<" ";
    }
}
void tree ::in(node *temp)
{
    if(temp!=NULL)
    {
        pre(temp->l);
        cout<<temp->word<<" ";
        pre(temp->r);
    }
}
void tree::in_nr(node *temp)
{
    stack <node*> s;
    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->l;
    }
    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        cout<<temp->word<<" ";
        temp=temp->r;
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->l;

        }
    }

}
void tree::pre_nr(node *temp)
{
    stack <node*> s;
    while(temp!=NULL)
    {
        cout<<temp->word<<" ";
        s.push(temp);
        temp=temp->l;
    }
    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        temp=temp->r;
        while(temp!=NULL)
        {
            cout<<temp->word<<" ";
            s.push(temp);
            temp=temp->l;
        }
    }
}
void tree::post_nr(node *temp)
{
    stack <node*> s1;
    stack <node*> s2;
    s1.push(temp);
    while(!s1.empty())
    {
        temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->l!=NULL)
        	s1.push(temp->l);

        if(temp->r!=NULL)
        	s1.push(temp->r);
    }
    while(!s2.empty())
    {
        temp=s2.top();
        s2.pop();
        cout<<temp->word<<" ";
    }
}
void tree ::search()
{
    node *temp;
    temp=root;
    string key;
    cout<<"\n Enter key you want to search ";
    cin>>key;
    while(temp!=NULL)
    {
        if(key==temp->word)
        {
            cout<<"\n WORD PRESENT ";
            return;
        }
        if(key<temp->word)
            temp=temp->l;
        else
            temp=temp->r;
    }
    cout<<"\n WORD NOT PRESENT ";
}
void tree ::update()

{
    node *temp;
        temp=root;
        string key;
        cout<<"\n Enter key you want to update ";
        cin>>key;
        while(temp!=NULL)
            {
                if(key==temp->word)
                {
                    cout<<"\n ENTER UPDATED DETAILS";
                    cout<<"\n Enter word ";
                    cin>>temp->word;
                    return;
                }
                if(key<temp->word)
                    temp=temp->l;
                else
                    temp=temp->r;
            }
            cout<<"\n WORD NOT PRESENT ";
}
void tree::d()
{
        int flag=0;
    string key;
    cout<<"\n Enter key to be deleted";
    cin>>key;
    node *temp,*parent;
    temp=root;
    while(temp!=NULL)
        {
            parent=temp;
            if(key==temp->word)
            {
                    flag=1;
                 break;
            }
            if(key<temp->word)
                temp=temp->l;
            else
                temp=temp->r;
        }
    if(flag==0)
    {
        cout<<"\n WORD NOT PRESENT ";
        return;
    }
    else
    {
        if(temp->l==NULL && temp->r==NULL)
        {
            if(temp->word<parent->word)
                parent->l=NULL;
            else
                parent->r=NULL;
            delete temp;
        }
        else if(temp->l==NULL && temp->r!=NULL)
        {
            if(temp->word<parent->word)
                parent->l=temp->r;
            else
                parent->r=temp->r;
            delete temp;
        }
        else if(temp->r==NULL && temp->l!=NULL)
        {
            if(key<parent->word)
                 parent->l=temp->l;
             else
                 parent->r=temp->l;
            delete temp;
        }
        else
        {
            node *cn;
            cn=temp->l;
            while(cn->r!=NULL)
            {
                cn=cn->r;
            }
            string x;
            x=cn->word;
            delete cn;
            temp->word=cn->word;
        }
    }
}
int main()
{
    tree q;
    int n;
    do
    {
        cout<<"\n Choose the task you wish to perform "<<endl;
        cout<<"\n 1.Enter word ";
        cout<<"\n 2.Show word in rec  preorder ";
        cout<<"\n 3.Show word in rec postorder ";
        cout<<"\n 4.Show word in rec inorder "<<endl;
        cout<<"\n 5.Show word in non rec  preorder ";
        cout<<"\n 6.Show word in non rec  postorder ";
        cout<<"\n 7.Show word in non rec  inorder "<<endl;
        cout<<"\n 8.Search word ";
        cout<<"\n 9.Update word "<<endl;
        cout<<"\n 10.Delete word "<<endl;
        cout<<"\n PRESS 0 TO EXIT "<<endl;
        cin>>n;
        switch(n)
        {
        case 1: int k;
                do
                {
                    q.create();
                    cout<<"\n PRESS 1 TO KEEP ADDING WORDS "<<endl;
                    cin>>k;
                }while(k==1);break;
        case 2: cout<<"\n Sequence is : ";q.pre(q.root);break;
        case 3: cout<<"\n Sequence is : "; q.post(q.root);break;
        case 4: cout<<"\n Sequence is : "; q.in(q.root);break;

        case 5: cout<<"\n Sequence is : "; q.pre_nr(q.root);break;
        case 6: cout<<"\n Sequence is : "; q.post_nr(q.root);break;
        case 7: cout<<"\n Sequence is : "; q.in_nr(q.root);break;

        case 8: q.search();break;
        case 9: q.update();break;

        case 10: q.d();break;

        case 0: break;

        }
    }while(n!=0);




}


