#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int compared(string a, string b)
{
    string ab=a.append(b);
    string ba=b.append(a);
    
//Either the value of the first character that does not match is greater in the compared string, or all compared characters match but the compared string is longer. (when>0)  string .compare().... by c++ reference
    return ab.compare(ba)>0 ? 1:0;
    
    // str1.compare(str2);. 如果相等則輸出為0，不等則輸出為-1
}

int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int n;
        cin>>n;
        vector<string> v;
        string t;
        for(int i=0;i<n;i++)
        {
            cin>>t;
            v.push_back(t);
        }
    
        sort(v.begin(), v.end(), compared);
    
        for(int i=0;i<n;i++)
        {
            cout<<v[i];
        }
        cout<<endl;
        v.clear();
    }
    return 0;
}
