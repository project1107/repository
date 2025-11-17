// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m,k;
//     cin>>n>>m>>k;
//     vector<vector<int>> hang;
//     for(int i=0;i<n;i++)
//     {
//         vector<int> lie;
//         for(int j=0;j<m;j++)
//         {
//             int a;
//             cin>>a;
//             lie.push_back(a);
//         }
//         hang.push_back(lie);
//     }
//     for(int p=0;p<k;p++)
//     {
//         int max=0;
//         pair<int,int> a={0,0};
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(hang[i][j]>max)
//                 {
//                     max=hang[i][j];
//                     a.first=i;
//                     a.second=j;
//                 }
//             }
//         }
//         hang.erase(hang.begin()+a.first);
//         n--;
//         for(auto& i:hang)
//         {
//             i.erase(i.begin()+a.second);

//         }
//         m--;
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m-1;j++)
//         {
//             cout<<hang[i][j]<<" ";
//         }
//         cout<<hang[i][m-1]<<endl;
//     }
// }

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        a.push_back(k);
    }
    for(int i=0;i<m;i++)
    {
        rotate(a.rbegin(),a.rbegin()+1,a.rend());
    }
    for(int i:a)
        cout<<i<<" ";
}