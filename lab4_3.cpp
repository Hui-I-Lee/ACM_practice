#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <cstdio>

using namespace std;
const int inf=0x3f3f3f3f;

struct Edge
{
    int v,x,y,t;
   // Edge(int f,int t,int o,int cl,int c):from(f),to(t),x(o),y(cl),t(c){}
};

struct heapnode
{
    int ver;
    int dist;
    bool operator < (const heapnode& that) const {
             return dist > that.dist;
         }
};

int d[10005];
bool done[10005];
vector<Edge> edge[10005];


int Dijkstra(int start, int finish)
{
    memset(d,inf,sizeof(d));
    memset(done, false, sizeof(done));

    d[start]=0;
    priority_queue<heapnode> q;
    q.push((heapnode){start, 0});
    
    
    while(!q.empty())
    {
        heapnode f=q.top();
        q.pop();
        int ver=f.ver;
        
        if(ver==finish)
            return f.dist;
        
        if(done[ver])
            continue;
        done[ver] = true;
        
        for(int i = 0; i < edge[ver].size(); i++)
        {
            Edge& b = edge[ver][i];
            int progress = d[ver] % (b.x + b.y);
            if(progress + b.t <= b.x)
            {
                if(d[b.v] > d[ver] + b.t)
                {
                    d[b.v] = d[ver] + b.t;
                    q.push((heapnode){b.v, d[b.v]});
                }
            }
            else
            {
                int need = d[ver] + b.t + b.x + b.y - progress;
                if(d[b.v] > need)
                {
                    d[b.v] = need;
                    q.push((heapnode){b.v, need});
                }
            }
        }
    }
    return d[finish];
}

int main()
{
    int testcase;
    scanf("%d", &testcase);
    
    
    while(testcase--)
    {
        int N,M,S,T;
        scanf("%d%d%d%d",&N,&M,&S,&T);
        
        for(int i=1;i<=N;i++)
        {
            edge[i].clear();
            //g[i].clear();
        }
        
        for(int i=0;i<M;i++)
        {
            int u,v,a,b,t;
            scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
            if(t>a) continue;
            edge[u].push_back((Edge){v,a,b,t});
            
        }
        
        int ans=Dijkstra(S,T);
        cout<<ans<<endl;
        //spfa(s);
        //cout<<dist[t]<<endl;
    }
    return 0;
}


/*
void spfa(int s)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        dist[i]=inf;
    }
    q.push(s);
    v[s]=1;
    dist[s]=0;
    
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        v[now]=0;
        for(int i=0;i<g[now].size();i++)
        {
            int nt=g[now][i].v;
            int t=g[now][i].t;
            int a=g[now][i].x;
            int b=g[now][i].y;
            if(a<t) continue;
            long long cost=0;
            
            if(dist[now]%(a+b) +t <= a)
            {
                cost=dist[now]+t;
            }
            else
            {
                cost = dist[now] + a + b - dist[now]%(a + b) + t;
            }
            if (cost < dist[nt])
            {
                dist[nt] = cost;
                if (!v[nt])
                {
                    v[nt] = 1,
                    q.push(nt);
                }
            }
            /*if(dist[now]%(a+b)+t<=a)
            {
                if(dist[nt]>dist[now]+t)
                {
                    dist[nt]=dist[now]+t;
                    {
                        v[nt]=1;
                        q.push(nt);
                    }
                }
            }
            else
            {
                if(dist[nt]>dist[now]+a+b-dist[now]%(a+b)+t)
                {
                    dist[nt]=dist[now]+a+b-dist[now]%(a+b)+t;
                    if(!v[nt])
                    {
                        v[nt]=1;
                        q.push(nt);
                    }
                }
            }
        }
    }
}
*/
/*
int arriveNext(int arrive,const Edge&e)
{
    int temp=arrive%(e.x+e.y);
    if(temp+e.t<=e.x)
        return arrive+e.t;
    return arrive+e.x+e.y-temp+e.t;
}

void Dijkstra()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    memset(dis,inf,sizeof(dis));
    dis[s]=0;
    pq.push({0,s});
    
    while(!pq.empty())
    {
        //auto now = *st.begin();
        pair<int,int> p;
        p=pq.top();
        pq.pop();
        if(dis[p.second]!=p.first)
            continue;
        
        for(int i:graph[p.second])
        {
            Edge&e=edges[i];
            int arrive=arriveNext(dis[p.second],e);//到达道路e终点的时间
            if(dis[e.to]>arrive)
            {
                dis[e.to]=arrive;
                pq.push({dis[e.to],e.to});
            }
        }
    }
}
*/

