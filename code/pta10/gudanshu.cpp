#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long t;
    cin>>n>>t;
    vector<long long> num;
    unordered_set<long long> nump;
    for(int i=0;i<n;i++)
    {
        long long temp;
        cin>>temp;
        num.push_back(temp);
        nump.insert(temp);
    }
    for(int i=0;i<n;i++)
    {
        long long temp=t-num[i];
        if(nump.find(temp)==nump.end()||(num[i]==temp&&count(num.begin(),num.end(),temp)==1))
            cout<<num[i]<<" ";
    }
}