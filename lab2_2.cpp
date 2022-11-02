#include <iostream>
#include <string>

using namespace std;
// aaba abaa
//   "aa"  "ba"    v.s.  "ab"  "aa"
// "aa", "b" , "a"    v.s.   "a" , "b", "aa"   => YES
string leastequalstring (string s)
{
    if(s.size()%2) return s;
    
    string x=leastequalstring(s.substr(0, s.size()/2));
    string y=leastequalstring(s.substr(s.size()/2 , s.size()));
    
    if(x<y) return x+y;
    else return y+x;
}

bool equal(string a, string b)
{
    return (leastequalstring(a) == leastequalstring(b));
}

int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        string a,b;
        cin>>a;
        cin>>b;
    
        if(equal(a,b))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
