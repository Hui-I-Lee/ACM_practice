#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int x,y,t,r;
};

bool cmp(node a, node b)
{
    return a.t<b.t;
}

long long int dist(node a, node b)
{
    long long int dis;
    dis=(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    return dis;
}


int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int n;
        cin>>n;
        node p[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].x>>p[i].y>>p[i].t>>p[i].r;
        }
        
        sort(p+1, p+1+n, cmp);
        int dp[n+1];
        for(int i = 1 ; i <= n ; i++)
        {
            dp[i] = p[i].r;
        }
        int ans=dp[1];
        
        for(int i = 2 ; i <= n ; i++)
        {
            for(int j = i-1 ; j >= 1 ; j--)
            {
                long long int a,d;
                a = (p[i].t-p[j].t)*(p[i].t-p[j].t);
                d = dist(p[i], p[j]);
                if(a >= d)
                {
                    dp[i] = max(dp[i], dp[j]+p[i].r);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout<<ans<<endl;
        
    }
    return 0;
}

