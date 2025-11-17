#include<bits/stdc++.h>
using namespace std;
void print(int times,char p)
{
    if(times>1)
    {
        for(int i=times;i>=0;i--)
    {
        for(int q=0;q<times-i;q++)
            cout<<" ";
        for(int j=0;j<i*2+1;j++)
        {
            cout<<p;
        }
        cout<<endl;
    }
    for(int i=1;i<=times;i++)
    {
        for(int q=0;q<times-i;q++)
            cout<<" ";
        for(int j=0;j<i*2+1;j++)
        {
            cout<<p;
        }
        cout<<endl;
    }
    }
    else
        cout<<p<<endl;
}
int sum(int i)
{
    return 2*i*i+4*i+1;
}
int main()
{
    int n;
    char p;
    cin>>n>>p;
    bool m=true;
    int times;
    int i=1;
    int least=0;
    while(m)
    {
        if(sum(i)>n)
        {
            m=false;
            times=i-1;
            least=n-sum(i-1);
        }
        i++;
    }
    print(times,p);
    cout<<least<<endl;
}