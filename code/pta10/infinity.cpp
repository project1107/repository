#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
    int v,n;
    cin>>v>>n;
    string name[n];
    int vil[n];
    double price[n];
    double minprice=INFINITY;
    int p=0;
    for(int i=0;i<n;i++)
    {
        cin>>name[i]>>vil[i]>>price[i];
        if(vil[i]<=10)
        {
            if(price[i]<minprice)
            {
                minprice=price[i];
                p=i;
            }
        }
    }
    cout<<name[p]<<" "<<vil[p]<<" "<<fixed<<setprecision(2)<<price[p]<<endl;
    
}