#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct person
{
    char gender;
    string father;
    string mother;
};
unordered_map<string,person> self;
unordered_map<string,vector<string>> ancestor;
void add_ancestor(const string& selfid,const string& zhang,int generation)
{
    if(generation>4)
    {
        return;
    }
    ancestor[selfid].push_back(zhang);
    if(self.count(zhang)&&self[zhang].father!="-1")
    {
        // ancestor[selfid].push_back(self[zhang].father);
        add_ancestor(selfid,self[zhang].father,generation+1);
        // add_ancestor(selfid,self[selfid].mother,generation+1);
    }
    if(self.count(zhang)&&self[zhang].mother!="-1")
    {
        // ancestor[selfid].push_back(self[zhang].mother);
        // add_ancestor(selfid,self[selfid].father,generation+1);
        add_ancestor(selfid,self[zhang].mother,generation+1);
    }
}
bool isrelated(const string& self1,const string& self2)
{
    for(const auto& i1:ancestor[self1])
    {
        for(const auto& i2:ancestor[self2])
        {
            if(i1==i2)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        person p;
        string selfid;
        cin>>selfid>>p.gender>>p.father>>p.mother;
        self[selfid]=p;
        // if(p.father!="-1") self[p.father].gender='F';
        // if(p.mother!="-1") self[p.mother].gender='M';
        // add_ancestor(selfid,selfid,0);
    }
    for(const auto& it:self)
    {
        add_ancestor(it.first,it.first,0);
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        string self1,self2;
        cin>>self1>>self2;
        if(self[self1].gender==self[self2].gender)
        {
            cout<<"Never Mind"<<endl;
        }
        else if(isrelated(self1,self2))
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
}