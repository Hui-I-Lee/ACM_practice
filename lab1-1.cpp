#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define inf 2147483647;
#define max 100001;
int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int m,n;
        cin>>m>>n;
    
        int r[max]={0};  //repeat
        vector<int> array1;  //initial line
        vector<int> array2;  //regular line
        //vector<int> array3;
        int t;
        for(int i=0;i<m;i++)
        {
            cin>>t;
            array1.push_back(t);
            r[t]++;
        }
        for(int i=0;i<n;i++)
        {
            cin>>t;
            array2.push_back(t);
        }
        ///
        int k=0;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                if(array2[j] == array1[i])
                {
                    array3.push_back(array2[j]);
                    array1[i]=inf;
                    k++;
                }
            }
        }
        sort(array1.begin(), array1.end());
    
        for(int i=0;i<m-k;i++)
        {
            array3.push_back(array1[i]);
        }
        for(int i=0;i<m;i++)
        {
            cout<<array3[i]<<" ";
        }
        cout<<endl;
        array1.clear();
        array2.clear();
        array3.clear();
    }
}
