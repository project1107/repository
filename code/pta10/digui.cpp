#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int person[8][8];
vector<string> right1;
int book[8];
bool look[8]={false};
void fen(int i)
{
    if(i==n)
    {
        string str="(";
        for(int j=0;j<n-1;j++)
        {
            str+=to_string(book[j])+", ";
        }
        str=str+to_string(book[n-1])+")";
        right1.push_back(str);
    }
    for(int j=0;j<m;j++)
    {
        if(person[i][j]==1&&look[j]==false)
        {
            book[i]=j+1;
            look[j]=true;
            fen(i+1);
            look[j]=false;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>person[i][j];
        }
    }
    fen(0);
    for(auto i:right1)
    {
        cout<<i<<endl;
    }
}
