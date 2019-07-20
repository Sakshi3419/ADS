#include <iostream>
using namespace std;
class graph
{
public:  int a[10][10],cost[10][10],sp[10][10];
        int n,visited[10],d[10],s[10];
        void rep_matrix();
        void prim();
        graph()
        {
            for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                        {
                            a[i][j]=0;
                            sp[i][j]=0;
                            cost[i][j]=0;
                        }
                }
           
        }

};
void graph::rep_matrix()
{

        cout<<"\n ENTER NUMBER OF NODES IN GRAPH ";
        cin>>n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                a[i][j]=0;
            }
        int k,x,y,w;
        do
        {
            cout<<"\n ENTER NODES WHICH HAVE VERTEX AMONG THEM ";
            cin>>x>>y;
            cout<<"\n ENTER WEIGHT ";
            cin>>w;
            a[x][y]=w;
            a[y][x]=w;
            cout<<"\n PRESS 1 TO CONTINUE ";
            cin>>k;
        }while(k==1);
        cout<<"\n Matrix representation of graph is "<<endl;
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        cout<<a[i][j]<<" ";
                    }
                cout<<endl;
            }
}
void graph::prim ()
{
    int e;
    int m,v,u,i,j,min;
	 for(int i=0;i<n;i++)             //initialising array to 0
            {
                visited[i]=0;
                d[i]=0;
                s[i]=0;
            }
    for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                        {
                             
                            sp[i][j]=0;
                            cost[i][j]=0;
                        }
                }
    for(i=0;i<n;i++)            //creating cost matrix
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0)
                cost[i][j]=9900;
            else
                cost[i][j]=a[i][j];
        }
    }
    
     
     //PRIMS ACTUAL LOGIC

   d[0]=0;
    visited[0]=1;

    for(j=1;j<n;j++)
    {
        d[j]=cost[0][j];
        s[j]=0;
        visited[j]=0;
    }

    min=0;
    e=n-1;
    while(e>0)
    {
        m=99;
        for(i=1;i<n;i++)
        {
            if(visited[i]==0 && d[i]<m)
            {
                m=d[i];
                v=i;
            }
        }

        u=s[v];
        sp[u][v]=d[v];
        sp[v][u]=d[v];
        e--;
        visited[v]=1;

    }
    for(i=1;i<n;i++)
    {
        if(visited[i]==0 && cost[i][v]<d[i])
        {
            d[i]=cost[i][v];
            s[i]=v;
        }
        min=min+cost[u][v];
    }
	 
	 
	 //end prims
	 
	 cout<<"\n  SPANNING TREE   : "<<endl;
    for(int i=0;i<n;i++)
     {
        for(int j=0;j<n;j++)
        {
            cout<<sp[i][j]<<" ";
        }
        cout<<endl;
    }
 	int sum=0;
	cout<<endl;
	 for(int i=0;i<n;i++)
	 sum+=d[i];
	 cout<<"\n  Minimum cost is : "<<sum;
}
int main()
{
    graph q;
    q.rep_matrix();
    cout<<endl;
    q.prim();
}


