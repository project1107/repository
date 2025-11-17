#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> road;
unordered_map<int,set<int>> maxroad;
void deep(int node,int i)
{
    if(road[node-1].size()==0)
    {
        maxroad[node-1].insert(i);
        return;
    }
    for(int j=0;j<road[node-1].size();j++)
    {
        deep(road[node-1][j],i+1);
    }
}
int main()
{
    int n;
    cin>>n;
    int roots[n]={0};
    int root;
    for(int i=0;i<n;i++)
    {
        vector<int> ro;
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int a;
            cin>>a;
            roots[a-1]++;
            ro.push_back(a);
        }
        road.push_back(ro);
    }
    for(int i=0;i<n;i++)
    {
        if(roots[i]==0)
        {
            root=i+1;
        }
    }
    deep(root,0);
    int maxi=-1;
    int maxdeep=-1;
    for(auto it:maxroad)
    {
        int p=*it.second.rbegin();
        if(p>maxdeep)
        {
            maxdeep=p;
            maxi=it.first+1;
        }
    }
    cout<<maxi<<endl;
}





// vector<int> vec = {1, 2, 3, 4, 5};
// auto it = vec.begin(); // it 指向第一个元素 1
// cout << *it << endl;   // 输出 1

// vector<int> vec = {1, 2, 3, 4, 5};
// auto it = vec.end(); // it 指向最后一个元素 5 的下一个位置
// --it;                // 将 it 移动到最后一个元素 5
// cout << *it << endl; // 输出 5



// #include <algorithm>
// vector<int> vec = {1, 2, 3, 4, 5};
// auto it = max_element(vec.begin(), vec.end()); // it 指向最大元素 5
// cout << *it << endl;                           // 输出 5


// vector<int> vec = {1, 2, 3, 4, 5};
// auto it = vec.rbegin(); // it 指向最后一个元素 5
// cout << *it << endl;    // 输出 5


// vector<int> vec = {1, 2, 3, 4, 5};
// auto it = vec.rend(); // it 指向第一个元素 1 的前一个位置
// --it;                 // 将 it 移动到第一个元素 1
// cout << *it << endl;  // 输出 1


