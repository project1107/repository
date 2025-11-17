#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> solution;
    for(int i=1;i<100;i++)
    {
        for(int j=0;j<100-i;j++)
        {
            int p=100-i-j;
            if(5*i+2*j+p==150)
            {
                solution.push_back(make_pair(i,make_pair(j,p)));
            }
        }
    } 
    if(n>solution.size())
    {
        for(pair<int,pair<int,int>> i:solution)
        {
            cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            cout<<solution[i].first<<" "<<solution[i].second.first<<" "<<solution[i].second.second<<endl;
        }
    }
}