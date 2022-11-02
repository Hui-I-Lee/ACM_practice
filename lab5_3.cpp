#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        string k,o;
        cin>>k;  //from small to big
        cin>>o;  //from big to small;
    
        int size=k.length();
        sort(k.begin(), k.end());
        sort(o.begin(), o.end());
        reverse(o.begin(), o.end());
    //cout<<k<<endl;
    //cout<<o<<endl;
        char c[size];
        int i=0;
        int j=0;
        int t=0, l=0, r=size-1, ir=(size-1)/2, jr=(size-1)/2;
        
        if(size%2)
        {
            jr--;
        }
        
        while(t<size)
        {
            if(t%2==0)
            {
                if(k[i]>=o[j])
               {
                   c[r--]=k[ir--];
               }
               else
               {
                   c[l++]=k[i++];
               }
        
            }
            else
            {
                if(o[j]<=k[i])
                {
                    c[r--]=o[jr--];
                }
                else
                {
                    c[l++]=o[j++];
                }
            }
            t++;
        }
        
        for(int f=0;f<size;f++)
        {
            cout<<c[f];
        }
        cout<<endl;
    }
    
       /* if(size%2==0)
        {
            for(int i=0;i<size/2;i++)
            {
                cout<<k[i];
                cout<<o[i];
            }
            cout<<endl;
        }
        else
        {
            for(int i=0;i<size/2;i++)
            {
                cout<<k[i];
                cout<<o[i];
            }
            cout<<k[size/2]<<endl;
        }*/
    
    return 0;
}
