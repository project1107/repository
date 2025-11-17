#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int num;
    cin>>num;
    int max_k=-1;
    int max_m=-1;
    for(int i=1;i<=31;i++)
    {
        int sum=0;
        int m=0;
        while(sum<num)
        {
            m++;
            sum=sum+pow(m,i);
        }
        if(sum==num&&i>max_k)
        {
            max_k=i;
            max_m=m;
        }
    }
    if(max_k==-1)
    {
        cout<<"Impossible for "<<num<<".";
    }
    else
    {
        for(int i=1;i<=max_m-1;i++)
        {
            cout<<i<<"^"<<max_k<<"+";
        }
        cout<<max_m<<"^"<<max_k;
    }

}