#include<bits/stdc++.h>
using namespace std;
set<string> node;
unordered_map<string,vector<int>> older;
unordered_map<string,vector<string>> nodes;
// int count(string ad)
// {
//     if(nodes[ad].empty())
//     {
//         return older[ad].size();
//     }
//     int num=older[ad].size();
//     for(auto it:nodes[ad])
//     {
//         num=num+count(it);
//     }
//     return num;
// }
//递归过多出现段错误，用栈或者队列替代递归
int count(string ad)
{
    int num=0;
    queue<string> old;
    old.push(ad);
    while(!old.empty())
    {
        string current=old.front();
        old.pop();
        num+=older[current].size();
        for(auto it:nodes[current])
        {
            old.push(it);
        }
    }
    return num;
}



int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        string a,b;
        cin>>a>>b;

        node.insert(b);
        if(isdigit(a[0]))
        {
            int old;
            old=stoi(a);
            older[b].push_back(old);
        }
        else
        {
            node.insert(a);
            nodes[b].push_back(a);
        }
    }
    char order;
    while(cin>>order)
    {
        if(order=='E')
            break;
        else if(order=='T')
        {
            int old;
            string ad;
            cin>>old>>ad;
            for(auto &it:older)
            {
                if(find(it.second.begin(),it.second.end(),old)!=it.second.end())
                {
                    it.second.erase(remove(it.second.begin(),it.second.end(),old),it.second.end());
                }
            }
            older[ad].push_back(old);
        }
        else
        {
            string ad;
            cin>>ad;
            cout<<count(ad)<<endl;
        }
    }
}