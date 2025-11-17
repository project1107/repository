#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int timetonum(int hour,int min,int ss)
{
    return hour*3600+min*60+ss;
}
int main()
{
    int n;
    vector<pair<int,int>> times;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int hour_begin,min_begin,ss_begin,hour_end,min_end,ss_end;
        char begin1,begin2,end1,end2;
        cin>>hour_begin>>begin1>>min_begin>>begin2>>ss_begin>>hour_end>>end1>>min_end>>end2>>ss_end;
        int begintime=timetonum(hour_begin,min_begin,ss_begin);
        int endtime=timetonum(hour_end,min_end,ss_end);
        times.push_back({begintime,0});
        times.push_back(make_pair(endtime,1));
    }
    sort(times.begin(),times.end());
    int activenum=0,maxnum=0;
    for(auto& time:times)
    {
        if(time.second==0)
        {
            activenum++;
        }
        else
        {
            activenum--;
        }
        maxnum=max(maxnum,activenum);
    }
    cout<<maxnum<<endl;
}