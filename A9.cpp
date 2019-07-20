#include<iostream>
using namespace std;
class q
{
	private:int n,rn[100];
	public: q()
			{
				n=0;
				for(int i=0;i<100;i++)
					rn[i]=0;
			}
			void g();
			void p(q);
			void gu(q ,q );
			void gi(q ,q );
			void gd(q ,q );
};
int main()
{
	q t,c,b,u,i,dc,db,n;
	int ch;
    do
	{ 
				cout<<"\n \n ENTER THE OPERATION YOU WISH TO PERFORM\n1. ENTER DATA\n2. DISPLAY DATA\n3. COMPUTE UNION\n4. COMPUTE INTERSECTION\n5. GET DIFFRENCE\n6. STUDENTS WHO PLAY NEITHER OF SPORT\n0. EXIT   ";
				cin>>ch;
				switch(ch)
				{
						case 1: cout<<"UNIVERSAL STUDENT DATA ";
								t.g();
								cout<<" STUDENT PLAYING CRICKET DATA "; 
								c.g();
								cout<<" STUDENT PLAYING BADMINTON DATA "; 
								b.g();
								break;


						case 2: cout<<"\n DETAILS OF STUDENTS ARE: ";
								cout<<"\n TOTAL NO OF STUDENT " ;
								t.p(t);
								cout<<"\n STUDENT PLAYING CRICKET " ;
								c.p(t);
								cout<<"\n STUDENT PLAYING BADMINOTN  " ;
								b.p(t);
								break;

						   
						case 3:cout<<"\n UNION IS  ";           
									u.gu(c,b);
									u.p(t);
									break;
							   
						case 4:cout<<"\n INTERSECTION IS ";               
									i.gi(c,b);
									i.p(t);
									break;
								
						case 5:cout<<"\n  DIFFRENCE IS"; 
									cout<<"\nCRICKET - BADMINTON ";             
									dc.gd(c,b);
									dc.p(t);
									break;
					 	case 7:		cout<<"\n BADMINTON - CRICKET ";
									db.gd(b,c);
									db.p(t);
									break;
						case 6:cout<<"\n STUDENTS WHO PLAY NEITHER CRICKET NOR BADMINTON  ";              
									n.gd(t,u);
									n.p(t);
									break;                         
					
		        }
    
    }while(ch!=0);
     
    return 0;
}
void q::g()
{ 
	cout<<"\n ENTER COUNT  ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cout<<"\n ENTER ROLL NO.";
	cin>>rn[i];
	}
}
void q::p(q a)
{ 
	if(a.n==0)
	cout<<"\n \n NO CURRENT DATA AVAILABLE";
	else
	{
	cout<<"\n ROLL NO. ARE: ";
	for(int i=0;i<n;i++)
	cout<<"\t"<<rn[i]; 
	cout<<"\n COUNT = "<<n;
	cout<<"\n";
	}
} 
void q:: gu(q c,q b)          
{
	 int count=0,i,j;
	 int flag=0;
	 for(j=0;j<b.n;j++)
	 {
	 	rn[j]=b.rn[j];
	 	count++;
	 }
	 for(i=0;i<c.n;i++)
	 {
	 	for(j=0;j<b.n;j++)
	 	{
	 		flag=0;
	 		if(c.rn[i]==b.rn[j])
	 		{
	 			flag=1;
	 			break;
	 		}
	 		
	 	}
	 	if(flag==0)
	 	{
	 		rn[count]=c.rn[i];
	 		count++;
	 	}
	 }
	 n=count;
}
void q:: gi(q c,q b)           
{ 
 int count=0,i,j;
	 int flag=0;
for(i=0;i<c.n;i++)
	 {
	 	for(j=0;j<b.n;j++)
	 	{
	 		flag=0;
	 		if(c.rn[i]==b.rn[j])
	 		{
	 			flag=1;
	 			break;
	 		}
	 		
	 	}
	 	if(flag==1)
	 	{
	 		rn[count]=c.rn[i];
	 		count++;
	 	}
	 }
	 n=count;
}
void q::gd(q c,q b)
{
	
  int count=0,i,j;
	 int flag=0;
	 for(i=0;i<c.n;i++)
	 {
	 	for(j=0;j<b.n;j++)
	 	{
	 		flag=0;
	 		if(c.rn[i]==b.rn[j])
	 		{
	 			flag=1;
	 			break;
	 		}
	 		
	 	}
	 	if(flag==0)
	 	{
	 		rn[count]=c.rn[i];
	 		count++;
	 	}
	 }
	 n=count;
}
