// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void performarrayqueue(vector<int> arr, vector<vector<int>> operations)
{
    int m = operations.size(); //10
    int n = arr.size();
    vector<int> vec;
    
    for(int i=0;i<m;i++)
    {
        int leftbound = operations[i][0]; //2
        int rightbound = operations[i][1];  //7
        for(int i=0;i<leftbound;i++)
        {
            vec.push_back(arr[n-1-i]);//9.8
        }
        for(int j=leftbound;j<=rightbound;j++)
        {
            vec.push_back(arr[j]);
        }
        for (int k=rightbound+1;k<n;k++) //1.0
        {
            vec.push_back(arr[n-1-k]);
        }
        for(int i=0;i<vec.size();i++)
        {
            cout<<vec[i]<<" ";
        }
        cout<<endl;
        vec.clear();
    }
    
}

int main() {
    // Write C++ code here
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};
    vector<vector<int> > operations = {{0,9},{4,5},{3,6},{2,7},{1,8},{0,9}};
    
    performarrayqueue(vec,operations);
    return 0;
}
