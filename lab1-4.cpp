#include <iostream>
#include <vector>
#include <map>
#define max 200001
using namespace std;


int main()
{
    int testcase;
    cin>>testcase;
    while(testcase!=0)
    {
        int n;
        cin>>n;
        int skill[n];
        int r[max]={0};  // repeat time of every number
        bool R[max]={false};  //appear already or not
        int most=0;
    
        for(int i=0;i<n;i++)
        {
            cin>>skill[i];
            r[skill[i]]++;
            if(most<r[skill[i]])
            {
                most=r[skill[i]];
            }
        }
        int k=0; // how many category of skill
        for(int i=0;i<n;i++)
        {
            if(R[skill[i]] == false)
            {
                k++;
                R[skill[i]]=true;
            }
        }
        if(k==1 && n!=1) k=1;
        else k--;
        
        if(most>k) cout<<k<<endl;
        else cout<<most<<endl;
        
        testcase--;
    }
    return 0;
}

