#include<bits/stdc++.h>
using namespace std;
void E(pair<int,int> &local)
{
    local.first++;
}
void S(pair<int,int> &local)
{
    local.second--;
}
void W(pair<int,int> &local)
{
    local.first--;
}
void N(pair<int,int> &local)
{
    local.second++;
}
int main()
{
    pair<int,int> local;
    local.first=0;
    local.second=0;
    string s;
    cin>>s;
    long long t;
    cin>>t;
    long long T=s.size();
    long long times=t/T;
    for(long long j=0;j<=times;j++)
    {
        if(j==times)
            T=t%T;
    for(long long i=0;i<T;i++)
    {
        switch(s[i])
        {
            case 'E':
                E(local);
                break;
            case 'S':
                S(local);
                break;
            case 'W':
                W(local);
                break;
            case 'N':
                N(local);
                break;
            default:
                break;
        }
    }
    }
    cout<<local.first<<" "<<local.second<<endl;
}