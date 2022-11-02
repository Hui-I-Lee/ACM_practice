#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int inf=2147483647;

/*
bool compare( pair<int,int>a, pair<int,int>b)
{
    if(a.first < b.first)
    {
        return true;
    }
    else if(a.first == b.first)
    {
        return a.second > b.second;
    }
    else
    {
        return false;
    }
   
}

int main()
{
    int testcase;
    cin>>testcase;
    
    while(testcase--)
    {
        int a;  //assignment
        cin>>a;
        
        pair<int,int> p;
        vector<pair<int,int>> v;
        vector<int> deadline;
        deadline.push_back(0);
        int t=0;
    
        for(int i=0;i<a;i++)
        {
            cin>>p.first>>p.second;
            if(p.first!=t)
            {
                t=p.first;
                deadline.push_back(t);
            }
            v.push_back(make_pair(p.first, p.second));
        }
    //deadline.push_back(0);
        sort(deadline.begin(), deadline.end());
        deadline.push_back(0);
        sort(v.begin(), v.end(), compare);
    
    int temp=0;
    long long int maxscore=0;
    int f=0;
        
        for(int i=0;i<a;i++)
        {
            if(v[i].first == deadline[f+1])
            {
                temp=i;
                for(int j=0;j<deadline[f+1]-deadline[f];j++)
                {
                    maxscore = maxscore + v[temp+j].second;
                }
                f++;
            }
            
        }
    cout<<maxscore<<endl;
        v.clear();
        deadline.clear();
    }
    return 0;
}
*/
int d[500000], s[500000], a[500000];

bool cmp1(int x, int y)   //deadline近的作業先做
{
    return d[x] < d[y];
}

int main()
{
    int testcase;
    cin>>testcase;
    
    while(testcase--)
    {
        int n;
        //cin>>n;
        scanf("%d", &n);
        int dd,ss;
        for(int i=0;i<n;i++)
        {
            a[i]=i;
            //cin>>dd>>ss;
            scanf("%d%d", &dd, &ss);
            d[i]=dd;
            s[i]=ss;
        }
        sort(a,a+n, cmp1);
        // priority_queue<Type, Container, Functional>
        priority_queue <int, vector<int>, greater<int> > pq;
        
        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (d[a[i]] > pq.size())
            {
                ans += s[a[i]];
                pq.push(s[a[i]]);
            }
            else if (d[a[i]] == pq.size() && s[a[i]] > pq.top())
            {
                ans -= pq.top();
                pq.pop();
                ans += s[a[i]];
                pq.push(s[a[i]]);
            }
        }
            cout << ans << endl;
    }
        
    return 0;
}
