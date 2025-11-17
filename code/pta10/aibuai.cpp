#include<bits/stdc++.h>
using namespace std;
struct node
{
    int type;
    int l;
    int r;
    node(int a=-1,int b=0,int c=0)
    {
        type=a;
        l=b;
        r=c;
    }
}tree[31];
int fa[31];
int dfs(int x,string num,int &q)
{
    int left,right;
    if(tree[x].type==-1)
    {
        char p=num[q];
        q++;
        return p-'0';
    }
    left=dfs(tree[x].l,num,q);
    if(tree[x].type==3)
    {
        return 1-left;
    }
    right=dfs(tree[x].r,num,q);
    if(tree[x].type==1)
    {
        return left&&right;
    }
    else
    {
        return left||right;
    }
}

int main()
{
    memset(fa,-1,sizeof(fa));
    int n;
    cin>>n;
    int type,a,b;
    for(int i=1;i<=n;i++)
    {
        cin>>type>>a;
        tree[i].type=type;
        tree[i].l=a;
        if(a!=0)
            fa[a]=i;
        if(type!=3)
        {
            cin>>b;
            tree[i].r=b;
            if(b!=0)
                fa[b]=i;
        }
    }
    int root=0;
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==-1)
        {
            root=i;
            break;
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string num;
        int q=0;
        cin>>num;
        int result=dfs(root,num,q);
        if(result==1)
        {
            cout<<"Ai"<<endl;
        }
        else
        {
            cout<<"BuAi"<<endl;
        }
    }
}

