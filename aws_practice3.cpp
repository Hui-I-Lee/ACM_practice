#include <iostream>

class Solution {
public: //sum rely * min avail
  int maximumStability(vector<int> reliability, vector<int> availability) {
    int n = reliability.size();
    int way = pow(2,n) - 1;
    vector<int> vec;

    for(int i=1;i<=n;i++)
  {
    
  }
  }
};


 #include <iostream>
 #include <vector>

 using namespace std;

 void print_subset(int * A, int n, int cur)
 {
     for(int i=0;i<cur;i++)
     {
         cout<<A[i]<<" , ";
     }
     cout<<endl;
     int s;
     if(cur != 0)
     {
         //cout<<"cur = "<<cur<<endl;
         s = A[cur-1] + 1;
     }
     else
     {
         s = 0;
     }
     for (int i=s; i<n ; i ++)
     {
         A[cur] = i;
         //cout<<"start recursive"<<endl;
         print_subset(A, n, cur+1);
     }
 }

 int main() {
     int A[10];
     int n=4;
     print_subset(A,n,0);
     return 0;
 }


