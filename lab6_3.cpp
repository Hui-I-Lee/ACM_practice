#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    while(true)
    {
        int N;
        string Mt;
        cin>>N>>Mt;
        
        if(N==0 && Mt=="BAKA")
            break;
        
        int M;
        M=atoi(Mt.c_str());
    
        int a,b,k;
        char c;
        int dist[101];
        int edge[100][2];
        int edge_cost[100];
    
        for(int i=0;i<M;i++)
        {
            cin>>a>>b>>c>>k;
        
            if(c == '>')
            {
                edge[i][0]=a+b;
                edge[i][1]=a-1;
                edge_cost[i]=-k-1;
            }
            else
            {
                edge[i][0]=a-1;
                edge[i][1]=a+b;
                edge_cost[i]=k-1;
            }
        }
    
        for(int i=0;i<=N;i++)
        {
            dist[i]=0;
        }
    
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<M;j++)
            {
                dist[edge[j][1]]=min(dist[edge[j][1]], dist[edge[j][0]]+edge_cost[j]);
            }
        }
    
        bool cycle;
        cycle=false;
    
        for(int j=0;j<M && !cycle;j++)
        {
            if(dist[edge[j][1]]>dist[edge[j][0]]+edge_cost[j])
            {
                cycle=true;
            }
        }
    
        if(cycle)
        {
            cout<<"There is no bus in Gensokyo."<<endl;
        }
        else
        {
            cout<<"All aboard the hype bus choo choo."<<endl;
        }
    }
    return 0;
}
