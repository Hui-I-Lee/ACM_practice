#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
/*
int main()
{
    int testcase;
    cin>>testcase;
    
   while(testcase--)
   {
       int n;
       cin>>n;
    
       int a,b;
       int x[n],y[n];
       vector<int> cx;
       vector<int> cy;
       int k;
       int same=0;
       for(int i=0;i<n;i++)
       {
           cin>>a>>b;
           x[i]=a;
           y[i]=b;
           k=a-b;
           if(k>0)
           {
               cx.push_back(abs(k));
           }
           else if (k<0)
           {
               cy.push_back(abs(k));
           }
           else
           {
               same++;
           }
       }
       sort(cx.begin(), cx.end());
       sort(cy.begin(), cy.end());

    
       int way=0;
       int xp=0;
       int yp=0;
    
       for(int i=0;i<n;i++)
       {
           if(x[i]>y[i])
           {
               way+=y[i];
               yp++;
           }
           else if(y[i]>x[i])
           {
               way+=x[i];
               xp++;
           }
           else
           {
               way+=x[i];
           }
       }
       int t;
       if(xp-yp+same<0)
       {
           t=yp-xp-same;
           t/=2;
           for(int i=0;i<t;i++)
           {
               way=way+cx[i];
           }
       }
       if(xp-yp-same>0)
       {
           t=xp-yp;
           t/=2;
           for(int i=0;i<t;i++)
           {
               way=way+cy[i];
           }
       }
       cout<<way<<endl;
       cx.clear();
       cy.clear();
   }
    return 0;
}
*/


int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int n;
        cin>>n;
        int cost[n][2]={0};
        int x,y;
        vector<int> diff;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            cost[i][0]=x;
            cost[i][1]=y;
            diff.push_back(x-y);
           // cout<<diff[i]<<endl;
        }
        int total=0;
        
        for(int i=0;i<n;i++)
        {
            total+=cost[i][0];
        }
        
        sort(diff.begin(), diff.end());
        
        for(int i=n/2;i<n;i++)
        {
            total-=diff[i];
        }
        cout<<total<<endl;
    }
    return 0;
}

