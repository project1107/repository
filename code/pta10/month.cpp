#include<iostream>
#include<string>
using namespace std;
int month[12]={0};
void init()
{
    month[0]=month[2]=month[4]=month[6]=month[7]=month[9]=month[11]=31;
    month[3]=month[5]=month[8]=month[10]=30;
}
bool run(int year)
{
    if((year%4==0&&year%100!=0)||year%400==0)
        return true;
    else
        return false;
}
int yeartoday(string n)
{
    int year,mon,day;
    sscanf(n.c_str(),"%d/%d/%d",&year,&mon,&day);
    if(run(year))
        month[1]=29;
    else
        month[1]=28;
    int sum=0;
    for(int i=0;i<mon-1;i++)
    {
        sum+=month[i];
    }
    sum+=day;
    return sum;
}
int main()
{
    init();
    string n;
    cin>>n;
    int day=yeartoday(n);
    cout<<day;
}