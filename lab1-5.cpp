//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define inf 2147483647;
using namespace std;

class Solution {
public:
 /*   int search(vector<int>& nums, int target, int tm)
    {
        for(int i=0;i<tm;i++)
        {
            if(target == nums[i])
                return i;
        }
        return -1;
    }*/
    int pivot;
    Solution(int p) : pivot(p)
    {
        //cout<<"pivot= "<<pivot<<endl;
    };
    
    void rotate(vector<int>& nums, int size)
    {
        vector<int> t=nums;
        //int size=nums.size();
        //cout<<"size= "<<size<<endl;
       // int k=size-pivot;
        //if(size%2!=0) pivot--;
        
        for(int i=0;i<size;i++)
        {
            nums[i]=t[(pivot+i+size)%size];
        }
       /*
        for(int i=0;i<size;i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<endl;*/
    }
    int search(vector<int>& nums, int l, int r, int target)
    {
        
        if (r >= l)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;
      
            if (nums[mid] > target)
                return search(nums, l, mid - 1, target);
            
            return search(nums, mid + 1, r, target);
        }
      
        return -1;
    }
    
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M, N;
    int tmp;
    vector<int> v;
    
    cin >> M >> N;
    int pivot=0;
    int smallest=inf;
    
    for(int i=0;i<M;i++)
    {
        cin >> tmp;
        v.push_back(tmp);
        if(tmp<smallest)
        {
            smallest=tmp;
            pivot=i;
        }

    }
    Solution sol(pivot);
    sol.rotate(v,M);
    int ans=0;
    while(N--)
    {
        cin >> tmp;  //tmp=target
        //ans = sol.search(v, tmp, tm)
        ans = sol.search(v, 0, M-1, tmp);
        if(ans==-1)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout << (ans+pivot)%M << endl;
        }
    }

    return 0;
}



