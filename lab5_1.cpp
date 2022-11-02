#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include <cstdlib>
using namespace std;

struct video
{
    int s;
    int f;
};
/*
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second<b.second;
}
*/

bool cmp(video& a, video& b)
{
    return a.f < b.f;
}

int main()
{
    int testcase;
    cin>>testcase;
    
    while(testcase--)
    {
        int n;
        cin>>n;
        //pair<int, int> p;
        //vector<pair<int, int>> v;
        vector<video> v;
        video b;
    
        int start,finish;
        for(int i=0;i<n;i++)
        {
            //cin>>p.first>>p.second;
            scanf("%d%d", &start, &finish);
            b.s=start;
            b.f=finish;
            v.push_back(b);
           // v.push_back(make_pair(p.first, p.second));
        }
    
        sort(v.begin(), v.end(), cmp);
        
        int finish_time=v[0].f;
        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (v[i].s >= finish_time)
            {
                count++;
                finish_time = v[i].f;
            }
        }
        cout << count << endl;
    }
       /* int temp=1;
        int index;
        int i;
        int max;
        int indextemp;
    
        for(index=0;index<n/2;index++)
        {
            indextemp=index;
            for(i=index+1;i<n-index;i++)
            {
                if(v[index].second == v[index+i].first)
                {
                //cout<<v[index].second<<" "<<v[index+i].first<<endl;
                    temp++;
                    index=index+i;
                }
            }
            if(temp>max)
            {
                max=temp;
            }
            index=indextemp;
        }
    
        cout<<max<<endl;*/
    //}
    return 0;
    
}
