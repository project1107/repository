// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     long long min,max;
//     cin>>min>>max;
//     bool p;
//     bool out=true;
//     long long num10[10];
//     for(int i=0;i<n;i++)
//     {
//         num10[i]=pow(10,i);
//     }
//     while(min<=max)
//     {
//         p=true;
//         for(int i=0;i<n;i++)
//         {
//             long long num=min/num10[n-i-1];
//             if(num%(i+1)!=0)
//             {
//                 p=false;
//                 break;
//             }
//         }
//         if(p)
//         {
//             cout<<min<<endl;
//             out=false;
//         }
//         min++;
//     }
//     if(out)
//     {
//         cout<<"No Solution"<<endl;
//     }
// }

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void zhengchu(long long x,int deep,long long minn,long long maxn,bool &flag)
{
    if(x>=minn&&x<=maxn)
    {
        cout<<x<<endl;
        flag=false;
    }
    for(int i=0;i<=9;i++)
    {
        long long num=x*10+i;
        if(num%(deep+1)==0)
        {
            zhengchu(num,deep+1,minn,maxn,flag);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    long long minn,maxn;
    cin>>minn>>maxn;
    bool flag=true;
    minn=max(minn,(long long)pow(10,n-1));
    maxn=min(maxn,(long long)pow(10,n)-1);
    for(int i=1;i<=9;i++)
    {
        zhengchu(i,1,minn,maxn,flag);
    }
    if(flag)
    {
        cout<<"No Solution"<<endl;
    }
}