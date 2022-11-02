#include <iostream>
#include <algorithm>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;

int line[755][755];
struct point
{
    int x,y;
};

struct enode
{
    int point1;
    int point2;
    int weight;
};

bool cmp(enode a, enode b)
{
    return a.weight<b.weight;
}

int dist(point a, point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int sets[755];
int ranks[755];

point p[755];
enode edge[565000];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        sets[i]=i;
        ranks[i]=0;
    }
}

int findp(int x)
{
    return x == sets[x] ? x : sets[x]=findp(sets[x]);
}
 
void joint(int a, int b)
{
    if (ranks[a] < ranks[b])
        sets[a] = b;
    else {
        if (ranks[a] == ranks[b])
            ranks[a] ++;
        sets[b] = a;
    }
}


void kruskal(int n)
{
    int r=0, uni=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(!line[i][j])   //不存在路
            {
                edge[r].point1=j;
                edge[r].point2=i;
                edge[r].weight = dist(p[i], p[j]);
                r++;
            }
            else
            {
                int A = findp(i);
                int B = findp(j);
                if (A != B)
                {
                    joint(A, B);
                    uni ++;
                }
            }
        }
    }
    if (uni+1 == n)
    {
        cout<<"0"<<endl;
        return;
    }
    
    sort(edge, edge+r, cmp);
    int add = 0;
    int road=0;
    pair<int, int> pp;
    vector<pair<int,int> > vpp;
    for (int i = 0; i < r; i++)
    {
        int A = findp(edge[i].point1);
        int B = findp(edge[i].point2);
        if (A != B)
        {
            joint(A, B);
            road++;
            pp.first=edge[i].point1;
            pp.second=edge[i].point2;
            vpp.push_back(make_pair(pp.first, pp.second));
            //cout<<edge[i].point1<<" "<<edge[i].point2<<endl;
            if (uni++ == n-1)
            {
                cout<<"0"<<endl;
                return;
            }
        }
    }
    cout<<road<<endl;
    vector<pair<int,int>>::iterator it;
    for(it=vpp.begin(); it!=vpp.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;

}

int main()
{
    int testcase;
    scanf("%d", &testcase);
    while(testcase--)
    {
        int n,m;
        
        int xt,yt;
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            //cin>>xt>>yt;
            scanf("%d%d", &xt, &yt);
            p[i].x=xt;
            p[i].y=yt;
        }
       
        init(n);
        scanf("%d", &m);
        memset(line, 0, sizeof(line));
        //int line[m+1]={0};
        int a,b;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            line[a][b]=1;
            line[b][a]=1;
        }
        
        kruskal(n);
       // if(testcase) cout<<endl;
    }
    
    return 0;
}

