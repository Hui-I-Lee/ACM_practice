#include<iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
#define unreachable -1;

const int UNREACHABLE = -1;

struct Edge
{
    int from;
    int to;
    int w;
    Edge(){}
    Edge(int _from, int _to, int _w)
    {
        from = _from;
        to = _to;
        w = _w;
    }
};

int main()
{
    int N;
    //cin>>N;
    scanf("%d", &N);
    
    while(N--)
    {
        int n, r, S, B;
        //cin>>n>>r>>B>>S;
        scanf("%d%d%d%d", &n, &r, &B, &S);
        
        vector<int> shortestPath(n,-1);
        shortestPath[S] = 0;
        vector< vector<Edge> > nodeEdges = vector< vector<Edge> >(n, vector<Edge>());

        int a, b, w;
        //create graph
        for( int j = 0 ; j < r ; j++ )
        {
            //cin>>a>>b>>w;
            scanf("%d%d%d", &a, &b, &w);
            nodeEdges[a].push_back( Edge(a, b, w) );
            nodeEdges[b].push_back( Edge(b, a, w) );
        }


      queue<int> next;
      vector<bool> inQueue(n, false);
      next.push(S);  // add to end

      while( !next.empty() )   // not empty
      {
          int current = next.front();
          next.pop();
          inQueue[current] = false;
                        // egde start from current node
          for( int i = 0 ; i < nodeEdges[current].size() ; i++ )
          {
              int toNode = nodeEdges[current][i].to;
              if( shortestPath[toNode] == -1 || shortestPath[current] + nodeEdges[current][i].w < shortestPath[toNode] )
              {
                  shortestPath[toNode] = shortestPath[current] + nodeEdges[current][i].w;
                  if( !inQueue[toNode] )
                  {
                      next.push(toNode);
                      inQueue[toNode] = true;
                  }
              }
          }
      }

      //printf("Case #%d: ", testcase);
      if( shortestPath[B] == UNREACHABLE )
      {
          cout<<"YOU DIED"<<endl;
      }
      else
      {
          cout<<shortestPath[B]<<endl;
      }
  }

  return 0;
}
