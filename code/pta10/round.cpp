//舍入到最接近的函数cmath库
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> num1,num2;
    for(int i=0;i<n;i++)
    {
        vector<int> lie;
        for(int j=0;j<m;j++)
        {
            int p;
            cin>>p;
            lie.push_back(p);
        }
        num1.push_back(lie);
        num2.push_back(lie);
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            double sum=num1[i][j]+num1[i-1][j]+num1[i+1][j]+num1[i][j-1]+num1[i][j+1];
            num2[i][j]=round(sum/5);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<num2[i][j]<<" ";
        }
        cout<<endl;
    }
}