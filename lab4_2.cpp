#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //int T,V,E;
    int testcase;
    bool found;
    
    scanf("%d",&testcase);
    while(testcase--)
    {
        int s,w;
        scanf("%d%d", &s, &w);
        
        int a,b,t;
        int edge[2000][2];
        int edge_time[2000];
        
        for(int i=0;i<w;i++)
        {
            scanf("%d%d%d",&a, &b, &t);
            edge[i][0]=a;
            edge[i][1]=b;
            edge_time[i]=t;
        }
        
        int dist[1000];
        bool reach[1000];
        
        dist[0]=0;
        reach[0]=true;
        for(int i=1;i<s;i++)
        {
            reach[i]=false;
        }
        
        for(int i=1;i<s;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(reach[edge[j][0]])
                {
                    if(!reach[edge[j][1]])
                    {
                        dist[edge[j][1]]=dist[edge[j][0]]+edge_time[j];
                        reach[edge[j][1]]=true;
                    }
                    else
                    {
                        dist[edge[j][1]] = min( dist[edge[j][1]], dist[edge[j][0]] + edge_time[j]);
                    }
                }
            }
        }
        bool found;
        found=false;
        
        for(int j=0;j<w && !found;j++)
        {
            if(reach[edge[j][0]])
            {
                if(!reach[edge[j][1]] || dist[edge[j][1]]>dist[edge[j][0]]+edge_time[j])
                {
                    found=true;
                }
            }
        }
        if(found)
        {
            //printf("possible\n");
            cout<<"This is the choice of Steins;Gate"<<endl;
        }
        else
        {
            cout<<"El Psy Kongroo"<<endl;
            //printf("not possible\n");
        }
    }
    
    return 0;
}
