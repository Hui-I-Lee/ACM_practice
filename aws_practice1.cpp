#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//head = [1,2,3,4,5] k=2
//output = [2,1,4,3,5]

void kgroupreverse(vector<int> &vec, int k)
{
    int groupnum = vec.size() / k; //0 k, k 2k 
    for(int i=0;i<groupnum;i++) // 02 3
    {
       reverse(vec.begin()+i*k,vec.begin()+(i+1)*k); 
    }
}


int main() {
    vector<int> vec={1,2,3,4,5};
    int k=3;
    kgroupreverse(vec,k);
    
    for(int v=0;v<vec.size();v++)
    {
        cout<<vec[v]<<" ";
    }
    return 0;
}
