#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> node;
vector<int> maxroad;
vector<int> current;
void zhao(int root,int deep)
{
    current.push_back(root);
    if(node[root].size()==0)
    {
        if(current.size()>maxroad.size())
        {
            maxroad=current;
        }
        else if(current.size()==maxroad.size())
        {
            maxroad=min(maxroad,current);
        }
    }
    else
    {
        for(auto it:node[root])
        {
            zhao(it,deep+1);
        }
    }
    current.pop_back();
}
int main()
{
    int n;
    cin>>n;
    int a[n]={0};
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        vector<int> bd;
        for(int j=0;j<k;j++)
        {
            int bingdu;
            cin>>bingdu;
            bd.push_back(bingdu);
            a[bingdu]=1;
        }
        node.push_back(bd);
    }
    int root;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
            root=i;
    }
    zhao(root,0);
    cout<<maxroad.size()<<endl;
    for(int i=0;i<maxroad.size()-1;i++)
    {
        cout<<maxroad[i]<<" ";
    }
    cout<<maxroad[maxroad.size()-1];
}