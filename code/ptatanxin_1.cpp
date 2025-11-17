#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int m,n,k,l,d;
    cin>>m>>n>>k>>l>>d;
    vector<int> x(m-1,0);
    vector<int> y(n-1,0);
    vector<int> maxx;
    vector<int> maxy;
    for(int i=0;i<d;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2)
        {
            int miny=min(y1,y2)-1;
            y[miny]++;
            /*不一样
            int miny=min(y1,y2);
            y[miny--]++;
            */
        }
        if(y1==y2)
        {
            int minx=min(x1,x2)-1;
            x[minx]++;
            /*不一样
            int minx=min(x1,x2);
            x[minx--]++;
            */
        }//min[x--]先使用x值索引，再计算x--，min[x-1]先计算x-1,再用x-1的值索引，x值不变
    }
    for(int i=0;i<k;i++)
    {
        auto it=max_element(x.begin(),x.end());
        int max_position=distance(x.begin(),it);
        x[max_position]=0;
        maxx.push_back(max_position+1);
    }
    /*
    while(k--)
    {
        for(auto& x:maxx)
        {
        
}
    }
    */
    for(int i=0;i<l;i++)
    {
        auto it=max_element(y.begin(),y.end());
        int max_position=distance(y.begin(),it);
        y[max_position]=0;
        maxy.push_back(max_position+1);
    }
    for(int numx:maxx)
    cout<<numx<<" ";
    cout<<endl;
    for(int numy:maxy)
    cout<<numy<<" ";
}