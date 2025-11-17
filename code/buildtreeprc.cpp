#include<iostream>
using namespace std;
struct treenode
{
    int data;
    treenode* left,*right;
    treenode(int x):data(x),left(NULL),right(NULL){}
};
treenode* buildtree(int node[],int i,int n)//层序遍历建树
{
    if(i<n)
    {
        treenode* root=new treenode(node[i]);
        root->left=buildtree(node,2*i+1,n);
        root->right=buildtree(node,2*i+2,n);
        return root;
    }
    else
        return NULL;
};
void qianxu(treenode* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        qianxu(root->left);
        qianxu(root->right);
    }
}
void houxu(treenode* root)
{
    if(root!=NULL)
    {
        houxu(root->left);
        houxu(root->right);
        cout<<root->data<<" ";
    }
}
int  main()
{
    int n;
    cin>>n;
    int node[10];
    for(int i=0;i<n;i++)
    {
        cin>>node[i];
    }
    int i=0;
    treenode* root=buildtree(node,i,n);
    qianxu(root);
    houxu(root);
}