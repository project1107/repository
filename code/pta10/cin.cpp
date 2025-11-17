#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int pos=s.find(' ');
    string a=s.substr(0,pos);
    string b=s.substr(pos+1,s.size());
    stringstream aa(a);
    stringstream bb(b);
    int a1,b1;
    bool flaga=true,flagb=true;
    if(aa>>a1&&a1>=1&&a1<=1000)
    {
        cout<<a1;
    }
    else
    {
        flaga=false;
        cout<<"?";
    }
    cout<<" + ";
    if(bb>>b1&&b1>=1&&b1<=1000)
    {
        cout<<b1;
    }
    else
    {
        flagb=false;
        cout<<"?";
    }
    if(flaga&&flagb)
    {
        cout<<" = "<<a1+b1;
    }
    else
    {
        cout<<" = ?";
    }
}