#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int testcase;
    cin>>testcase;
    
    int dp[505][505];
    char s[505];
    
    while(testcase--)
    {
        int n;
        cin>>n;
        cin>>(s+1);
    //scanf("%d", &n);
    //scanf("%s", s + 1);  //cin string from index 1
    
        // dp[f][r]= minus between f, r min eli time
        for (int i = 1; i <= n; i++)
        {
            dp[i][i] = 1;   //minus on itself
        }
    
        for (int len = 2; len <= n; len++)
        {
            for (int l = 1; l + len - 1 <= n; l++)
            {
                int r = l + len - 1;
                if (s[l] == s[r])        //一樣的話被同時消掉且移近so +1 than 距離變小
                {
                    dp[l][r] = dp[l + 1][r - 1] + 1;
                }
                else  //不同則一個人移動 刪掉自己
                {
                    dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
                }
                for (int k = l; k <= r; k++)
                {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] - 1);
                }
            }
        }
        cout<<dp[1][n]<<endl;
    }
   
    return 0;
}

