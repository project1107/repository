#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        string str;
        getline(cin,str);
        transform(str.begin(),str.end(),str.begin(),::tolower);
        if(str.find("shinto mekkaku")!=string::npos)
        cout<<"Medaka Kuroiwa"<<endl;
        else
        cout<<"Bonnjinn"<<endl;
    }
}