#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

//#define T 10000 //樓
//#define N 100   //ball
const int inf=0x3f3f3f3f;
//int dp[10005][10005]={0};
/*
int main()
{
    //vector<vector<int>> dp(T + 1, vector<int>(N + 1));
    
    while(true)
    {
        int N,T;
        cin>>N>>T;  // ball floor
        
        if(N==0 && T==0)
        {
            break;
        }
        int dp[T+1][N+1]={0};
    
    for(int i=1;i<=T;i++)  //樓
    {
        dp[i][1]=i;
    }
    //cout<<"~~~~~~"<<endl;
    for(int j=1;j<=N;j++)  //球
    {
        dp[1][j]=1;
    }
    //cout<<"!!!!!!"<<endl;
    for(int i=2;i<=T;i++)
    {
       for(int j=2;j<=N;j++)
       {
           dp[i][j]=inf;
           for(int k=1;k<=i;k++)
           {
                dp[i][j] = min(dp[i][j],max(dp[k-1][j-1],dp[i-k][j])+1);
               //cout<<"@@@@@"<<endl;
           }
        }
    }
        cout<<dp[T][N]<<endl;
    
    }
  
     return 0;
 }
*/

int main()
{
    while(true)
    {
        int K,N; //egg floor
        cin>>K>>N;
        if(K==0 && N==0)
            break;
        vector<int> dp(K+1);
        int res=0;
        for (; dp[K] < N; res++)
        {
            for (int i = K; i > 0; i--)
            {
                dp[i] = dp[i] + dp[i - 1] + 1;
            }
        }
        cout<<res<<endl;
        
    }
}


