#include <iostream>
#include <vector>
using namespace std;
int a[7];

void judge(int num)
{
    if(num<=a[2])
    {
        a[2]=a[2]-num;
    }
    else
    {
        int num1=(num-a[2])*4;
        a[1]=a[1]-num1;
        a[2]=0;
    }
}

int main()
{
    
    while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6])
    {
        if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0)
            break;
        int total;
        total=a[6];  //6*6 1
        total=total+a[5];   // 5*5  1*1 for 11
        a[1]=a[1]-a[5]*11;
        total=total+a[4];  // 4*4  2*2 for five
        int num2=a[4]*5;
        judge(num2);
       /* if(num2<a[2])
        {
            a[2]=a[2]-num2;
        }
        else
        {
            int num1=(num2-a[2])*4;
            a[1]=a[1]-num1;
            a[2]=0;
        }*/
        total=total+a[3]/4+bool(a[3]%4);  //if lest still need 1
        a[3]=a[3]%4;
    
        if(a[3]==1)
        {
            judge(5);
            a[1]=a[1]-7;
        }
        if(a[3]==2)
        {
            judge(3);
            a[1]=a[1]-6;
        }
        if(a[3]==3)
        {
            judge(1);
            a[1]=a[1]-5;
        }
    
        total=total+a[2]/9+bool(a[2]%9);
        a[2]=a[2]%9;
    
        if(a[2]>0)
        {
            int num_1=(9-a[2])*4;
            a[1]=a[1]-num_1;
        }
        if(a[1]>0)
        {
            total=total+a[1]/36+bool(a[1]%36);
        }
        cout<<total<<endl;
    }
    return 0;
}
