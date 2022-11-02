#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int inf=2147483647;

struct node
{
    int a;
    int b;
    int w;
};

node edge[10005];
int par[10005]={0};
int n,m;

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
    }
}

bool cmp(node a, node b)
{
    return a.w<b.w;
}

int findp(int x)
{
    return x == par[x] ? x : par[x]=findp(par[x]);
}

int kruskal()
{
    int mind = inf;
    
    for (int l = 0; l < m; l++)
    {
        init(n);
        int cnt = n - 1;
        
        for (int r = l; r < m; r++)
        {
            int dx = findp(edge[r].a);
            int dy = findp(edge[r].b);
            if (dx != dy)
            {
                if (dx < dy)
                {
                    par[dy] = dx;
                }
                else
                {
                    par[dx] = dy;
                }
                cnt--;
            }
            if (cnt == 0)
            {
                mind = min(mind, edge[r].w - edge[l].w);
                break;
            }
        }
    }
    return mind;

}

int main()
{
    int testcase;
    scanf("%d", &testcase);
    while(testcase--)
    {
        scanf("%d%d", &n, &m);
        int at,bt,wt;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d", &at, &bt, &wt);
            edge[i].a = at;
            edge[i].b = bt;
            edge[i].w = wt;
        }
        
        sort(edge, edge + m, cmp);
        int ans = kruskal();
        if (ans == inf)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
    
}
