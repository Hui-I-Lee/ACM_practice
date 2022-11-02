#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
//int N;


bool bfs(vector<vector<int>> rGraph, int s, int t, int *parent, int N)
{
    //cout<<"s= "<<s+1<<", t= "<<t+1<<endl;
    bool visited[N+2];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    int u;
    while (!q.empty())
    {
       
        u = q.front();
        q.pop();
        for (int v = 0; v < N+2; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t] == true;
}


int fordFulkerson(vector<vector<int>> graph, int s, int t, int N)
{
    int u, v;
    vector<vector<int>> rGraph((N+2), vector<int>(N+2));

    for (u = 0; u < N+2; u++)
    {
        for (v = 0; v < N+2; v++)
        {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[N+2];
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent, N))
    {
        int path_flow = inf;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        ///cout<<"pathflow= "<<path_flow<<endl;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        //cout<<"maxflow= "<<max_flow<<endl;
        max_flow += path_flow;
    }

    return max_flow;
}


int main()
{
    int testcase;
    cin>>testcase;
    
    while(testcase--)
    {
        int N, w, pp, m;
        cin>>N>>w>>pp>>m;
    //int graph[N][N];
        vector<vector<int>> graph((N+2),vector<int>(N+2));
        vector<int> power_plant;
        vector<int> machine;
    
        int k;
        for(int i=0;i<pp;i++) //source
        {
            cin>>k;
            power_plant.push_back(k-1);
            graph[N][k-1]=inf;
        }
    
        for(int i=0;i<m;i++)  //sink
        {
            cin>>k;
            machine.push_back(k-1);
            graph[k-1][N+1]=inf;
        }
    
        int a,b,c;
        for(int i=0;i<w;i++)
        {
            cin>>a>>b>>c;
            graph[a-1][b-1]=c;
        }
    //cout<<"test: "<<power_plant<<" "<<machine[0]<<endl;
        cout<<fordFulkerson(graph ,N, N+1, N)<<endl;
        
        graph.clear();
        power_plant.clear();
        machine.clear();
    
    }
    return 0;
    
}
