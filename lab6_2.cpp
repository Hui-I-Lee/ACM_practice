#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int inf=0x3f3f3f3f;

int minimumMountainRemovals(vector<int>& nums)
{
    vector <int> v;
    int l[1005], r[1005], ans = 1000;
    int s=nums.size();
    
    for (int i = 0; i < s; i++)
    {
        if (v.empty() || nums[i] > v.back())  //up++ from front
        {
            v.push_back(nums[i]);
            l[i] = v.size();
        }
        else
        {
            //change index
            int idx = lower_bound(v.begin(), v.end(), nums[i])-v.begin();
            v[idx] = nums[i];
            l[i] = idx+1;
        }
    }
    v.clear();
    
    for (int i = s-1; i >= 0; i--)
    {
        if (v.empty() || nums[i] > v.back())
        {                           // up++ from tail
            v.push_back(nums[i]);
            r[i] = v.size();
        }
        else
        {
            int idx = lower_bound(v.begin(), v.end(), nums[i])-v.begin();
            v[idx] = nums[i];
            r[i] = idx+1;
        }
    }
    for (int i = 0; i < s; i++)
    {
        if (l[i] < 2 || lds[i] < 2) continue;
        ans = min(ans, s - ( l[i] + r[i] - 1 ));
    }
    return ans;
}

int main()
{
    int testcase;
    //cin>>testcase;
    scanf("%d", &testcase);
    
    while(testcase--)
    {
        int n,t;
        //cin>>n;
        scanf("%d", &n);
        vector<int> vec;
        for(int i=0;i<n;i++)
        {
            //cin>>t;
            scanf("%d", &t);
            vec.push_back(t);
        }
        cout<<minimumMountainRemovals(vec)<<endl;
        vec.clear();
    }
    return 0;
}



/*
int minimumMountainRemovals(vector<int> nums)
{
    int s=nums.size();
    vector<int> lis(s,1); //longest increase sub end with nums[i]
    vector<int> lds(s,1);  //longest decrease ...
    
    // length=lis+lds-1
    // for up
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    
    // for down
    for (int i = s - 1; i >= 0; i--)
    {
        for (int j = s - 1; j > i; j--)
        {
            if (nums[i] > nums[j])
            {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    
    int ans = inf;
    for (int i = 0; i < s; ++i)
    {
        if (lis[i] < 2 || lds[i] < 2) continue;
        ans = min(ans, s - (lis[i] + lds[i] - 1));
    }
    return ans;
   
}
*/
