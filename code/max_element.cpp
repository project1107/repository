#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[3];
    for(int i=0;i<3;i++)
    {
        cin>>num[i];
    }
    int *max=max_element(num,num+3);
    int *min=min_element(num,num+3);
    cout<<"Maximum element is "<<*max<<endl;
    cout<<max-num<<endl;
    cout<<"Minimum element is "<<*min<<endl;
    cout<<min-num<<endl;
    cout<<fixed<<setprecision
}