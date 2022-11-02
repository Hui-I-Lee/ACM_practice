#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        pair<int, int> p;
        vector<pair<int, int>> vec;
        vector<int> fry;
        vector<int> sause;
        
        for(int i=0;i<k;i++)
        {
            cin>>p.first>>p.second;
            vec.push_back(make_pair(p.first, p.second));
            fry.push_back(p.first);
            sause.push_back(p.second);
        }
        
        vector<pair<int, int>> temp;
        vector<int> tempfry;
        vector<int> tempsause;
        
        for(int i=0;i<k;i++)
        {
            if(find(tempfry.begin(), tempfry.end(),vec[i].first) == tempfry.end() && find(tempsause.begin(), tempsause.end(), vec[i].second)==tempsause.end())
            {
                temp.push_back(vec[i]);
                tempfry.push_back(vec[i].first);
                tempsause.push_back(vec[i].second);
            }
        }
        cout<<temp.size()<<endl;
        vec.clear();
        fry.clear();
        sause.clear();
        temp.clear();
        tempfry.clear();
        tempsause.clear();
        
    }
    return 0;
}
