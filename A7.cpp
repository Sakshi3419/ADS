#include<iostream>
using namespace std;
struct node
{
    long int num;
    string name;

};
class phone
{
    private: node nn[10];
    public: void search();
            int hashf(long int k);
            void tb();
            void dis();
            void update();
            void delete_pn();
            phone()
            {
                for(int i=0;i<10;i++)
                    {
                		nn[i].num=-1;
                		nn[i].name="----------";
                    }
            }
};
int phone::hashf(long int k)
{
    int x;
    x=k%10;
    if(nn[x].num==-1)
        return x;
    else
    {
    		int i=x+1;
    	do
    	{
    		  if(nn[i].num==-1)
    		                return i;
    		  i=(i+1)%10;
    	}while(i!=x);

    }
}
void phone::tb()
{
    int p;
    long int x;
    cout<<"\nENTER TELEPHONE NUMBER: ";
    cin>>x;
    p=hashf(x);
    nn[p].num=x;
    cout<<"\nENTER NAME: ";
    cin>>nn[p].name;

}
void phone::dis()
{
    for(int i=0;i<10;i++)
    {
       // if(nn[i].num!=-1)
       // {
            cout<<"\nTELEPHONE NUMBER: ";
            cout<<nn[i].num;
            cout<<"\tNAME: ";
            cout<<nn[i].name;


       // }
    }
}
void phone::search()
{
	long int p;
	int flag=0;
	cout<<"\nENTER NUMBER TO BE SEARCHED ";
	cin>>p;
    int x;
    x=p%10;
    if(p==nn[x].num)
    {
    	cout<<"\n TELEPHONE NUMBER: " <<nn[x].num;
        cout<<"\t  NAME: "<<nn[x].name;
        flag=1;

    }
    else
    {

		for(int i=x+1;i!=x;i=(i+1)%10)
		{
			if(nn[i].num==p)
			{
				cout<<"\n TELEPHONE NUMBER: " <<nn[i].num;
				cout<<"\t NAME: "<<nn[i].name;
				 flag=1;
				break;
			}
		}
    }
    if(flag=0)
    	cout<<"\n Record Not found ";

}
void phone::update()
{
	   long int p;
		cout<<"\nENTER NUMBER TO BE UPDATED ";
		cin>>p;
	    int x,i;
	    x=p%10;
	    if(nn[x].num==-1)
	    {
	    	cout<<"\n ENTRY NOT FOUND ";
	    }
	    else
	    {
	    	 if(p==nn[x].num)
	    	    {
	    	    	cout<<"\n ENTER UPDATED RECORD";
	    	    	cout<<"\n TELEPHONE NUMBER: ";
	    	    	cin>>nn[x].num;
	    	        cout<<"\t  NAME: ";
	    	        cin>>nn[x].name;
	    	        return;
	    	    }
	    	    else
	    	    {

	    			for(int i=x+1;i!=x;i=(i+1)%10)
	    			{
	    				if(nn[i].num==p)
	    				{
	    					cout<<"\n ENTER UPDATED RECORD";
	    						    	    	cout<<"\n TELEPHONE NUMBER: ";
	    						    	    	cin>>nn[x].num;
	    						    	        cout<<"\t  NAME: ";
	    						    	        cin>>nn[x].name;
	    					break;
	    				}
	    			}
	    	    }
	    }
}
void phone ::delete_pn()
{
	 long int p;
	 cout<<"\nEnter number to be deleted: ";
	 cin>>p;
	 int x;
	    x=p%10;
	    if(p==nn[x].num)
	    {
	    	 nn[x].num=-1;
	    	 nn[x].name="----------";

	    }
	    else
	    {

			for(int i=x+1;i!=x;i=(i+1)%10)
			{
				if(nn[i].num==p)
				{
					 nn[x].num=-1;
					 nn[x].name="----------";
				     break;
				}
			}
	    }
}
int main()
{
    phone w;
    int n;
    do
    	{
    		cout<<"\n****************** TELEPHONE DIRECTORY ******************";
    		cout<<"\n1.Enter record";
    		cout<<"\n2.Display record";
    		cout<<"\n3.Search ";
    		cout<<"\n4.Update";
    		cout<<"\n5.Delete ";
    		cout<<"\n0.EXIT ";
    		cin>>n;
    		switch(n)
    		{
    			case 1:int k;do
    			{
    					w.tb();
    					cout<<"\n PRESS 1 TO CONTINUE ADDING RECORD ";
    					cin>>k;
    			}while(k!=0);break;

    			case 2:w.dis();break;
    			case 3:w.search();break;
    			case 4:w.update();break;
    		 	case 5:w.delete_pn();break;
    			case 0:break;
    			default: cout<<"ENTER VALID OPTION ";

    		}
    	}while(n!=0);
}






































