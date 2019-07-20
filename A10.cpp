#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class q
{
	private: char n[10],name[20], div;
	public: void get()
			{
				cout<<"\n ENTER NAME: ";
				cin>>name; 
				cout<<"\n ENTER ROLL NUMBER: ";
				cin>>n; 
				cout<<"\n ENTER DIVISION: ";
				cin>>div; 
			}
			void p()
			{
				cout<<"\n NAME: "<<name;
				cout<<"\t ROLL NUMBER: "<<n;
				cout<<"\t DIVISION: "<<div;
			}
			inline char* get_n() { return n;}
			inline char* get_name() { return name;}

};
int main()
{
	q w;
	int n,repeat,count=0,i=0; 
	do
	{
		cout<<"\n 1. CREATE DIRECTORY";
		cout<<"\n 2. DISPLAY RECORD";
		cout<<"\n 3. SEARCH RECORD BY NUMBER";
		cout<<"\n 4. SEARCH RECORD BY NAME";
		cout<<"\n 5. UPDATE RECORD";
		cout<<"\n 0. EXIT ";
		cout<<"\n YOUR CHOICE : ";
		cin>>n; 
		switch(n)
		{
				case 1: { 
							ofstream out;
							out.open("ab.txt",ios::app|ios::binary);
							do
							{
								w.get();
								out.write((char*)&w,sizeof(w)); 
								cout<<"\n PRESS 1 TO CONTINUE ";
								cin>>repeat;

							}while(repeat==1); 
							out.close();break; 
						}	

				case 2: {
							ifstream in;
							in.open("ab.txt",ios::in|ios::binary);

							while(in.read((char*)&w,sizeof(w))) 
								w.p();  
							in.close();break;
						}

				case 3: {
							char str[20];
							ifstream i;
							int flag=0;
							i.open("ab.txt",ios::in|ios::binary);

							cout<<"\n ENTER NUMBER TO BE SEARCHED  ";
							cin>>str;

							while(!i.eof())
							{
								i.read((char *)&w,sizeof(w));
								if(strcmp(str,w.get_n())==0)
								{
									flag=1;
									break;
								}
							}
							if(flag==1)
								w.p();
							else
								cout<<"\n RECORD NOT FOUND! ";break;
						}

				case 4: {
							char str[20];

							ifstream i;
							int flag=0;
							i.open("ab.txt",ios::in|ios::binary);

							cout<<"\n ENTER NAME TO BE SEARCHED  ";
							cin>>str;

							while(!i.eof())
							{
								i.read((char *)&w,sizeof(w));
								if(strcmp(str,w.get_name())==0)
								{
									flag=1;
									break;
								}
							}
							if(flag==1)
								w.p();
							else
								cout<<"\n RECORD NOT FOUND! ";break;
						}


				case 5: {
							char str[20];
							fstream f;
							int flag=0;
							f.open("ab.txt",ios::in|ios::binary|ios::out);
							cout<<"\n ENTER NUMBER TO BE  UPDATED";
							cin>>str;
							while(!f.eof())
							{
								f.read((char*)&w,sizeof(w));
								if(strcmp(str,w.get_n())==0)
								{
									flag=1;
									f.seekg(-sizeof(w),ios::cur);
									w.get();
									f.write((char*)&w,sizeof(w));
									break;
								}
							}
							if(flag==1)
								cout<<"\n UPDATED! ";
							else
							{
								cout<<"\n RECORD NOT FOUND ";

							}
							f.close();
							break;
						}	
				case 0:	break;               
		}
		
	}while(n!=0);
	return 0;
}
