#include<iostream>
#include<string>
using namespace std;
int main()
{
    string time;
    int num;
    cin>>time>>num;
    int hour,minute;
    if(time.size()==3)
    {
        hour=time[0]-'0';
        minute=(time[1]-'0')*10+time[2]-'0';
    }
    else
    {
        hour=(time[0]-'0')*10+time[1]-'0';
        minute=(time[2]-'0')*10+time[3]-'0';
    }
    if(num>0)
    {
        minute+=num%60;
        hour=hour+num/60+minute/60;
        minute%=60;
    }
    else
    {
        minute+=num;
        hour=hour+minute/60;
        minute%=60;
        if(minute<0)
        {
            hour--;
            minute+=60;
        }
    }
    cout<<hour;
    if(minute<10)
    {
        cout<<"0"<<minute;
    }
    else
        cout<<minute;
}