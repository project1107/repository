#include<iostream>
#include<string>
using namespace std;
int wan(string password)
{
    if(password.size()<6||password.size()>80)
    {
        return 1;
    }
    bool num=false;
    bool word=false;
    for(int i=0;i<password.size();i++)
    {
        if(password[i]>='0'&&password[i]<='9')
        {
            num=true;
        }
        else if((password[i]>='a'&&password[i]<='z')||(password[i]>='A'&&password[i]<='Z'))
        {
            word=true;
        }
        else if(password[i]=='.')
        {
            
        }
        else
        {
            return 2;
            break;
        }
    }
    if(num==true&&word==true)
    {
        return 0;
    }
    else if(word==false&&num==true)
    {
        return 4;
    }
    else if(word==true&&num==false)
        return 3;
    else
        return 2;
}
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        string ps;
        getline(cin,ps);
        int p=wan(ps);
        switch(p)
        {
            case 0:
                cout<<"Your password is wan mei."<<endl;
                break;
            case 1:
                cout<<"Your password is tai duan le."<<endl;
                break;
            case 2:
                cout<<"Your password is tai luan le."<<endl;
                break;
            case 3:
                cout<<"Your password needs shu zi."<<endl;
                break;
            case 4:
                cout<<"Your password needs zi mu."<<endl;
                break;
        }
    }
}