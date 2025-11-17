#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    bool flaga=true,flagb=true;
    int bet=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ')
        {
            bet=i;
            break;
        }
    }
    int a=0,b=0;
    for(int i=0;i<bet;i++)
    {
        if(str[i]<'0'||str[i]>'9')
        {
            flaga=false;
            break;
        }
        else
        {
            a=a*10+(str[i]-'0');
        }
    }
    for(int i=bet+1;i<str.size();i++)
    {
        if(str[i]<'0'||str[i]>'9')
        {
            flagb=false;
            break;
        }
        else
        {
            b=b*10+(str[i]-'0');
        }
    }
    if(a>=1&&a<=1000&&flaga==true)
    {
        cout<<a;
    }
    else
    {
        cout<<"?";
        flaga=false;
    }
    cout<<" + ";
    if(b>=1&&b<=1000&&flagb==true)
    {
        cout<<b;
    }
    else
    {
        cout<<"?";
        flagb=false;
    }
    if(flaga==false||flagb==false)
    {
        cout<<" = ?";
    }
    else
    {
        cout<<" = "<<a+b;
    }
}