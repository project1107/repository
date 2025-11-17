#include<iostream>
#include<string>
#include<cmath>
using namespace std;
bool zhishu(int num)
{
    if(num<2)
    return false;
    for(int i=2;i<sqrt(num);i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str;
    int maxn=1,minn=1;
    int word[26]={0};
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        word[str[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(word[i]>maxn)
        maxn=word[i];
        if(word[i]!=0&&word[i]<minn)
        minn=word[i];
    }

    if(zhishu(maxn-minn))
    {
        cout<<"Lucky Word"<<endl;
    }
    else
    {
        cout<<"No Answer"<<endl;
    }
    cout<<maxn-minn<<endl;
}