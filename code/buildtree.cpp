#include<iostream>
#include<vector>
using namespace std;
struct treenode
{
    int data;
    treenode *left,*right;
    treenode(int x):data(x),left(NULL),right(NULL){}
};
treenode *buildtree(int node[],int i,int n)
{
    if(i>=n)
        return NULL;
    treenode* root=new treenode(node[i]);
    root->left=buildtree(node,2*i+1,n);
    root->right=buildtree(node,2*i+2,n);
    return root;
};
void couttree(treenode* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        couttree(root->left);
        couttree(root->right);
    }
};
void zhongxu(treenode* root)
{
    if(root!=NULL)
    {
        zhongxu(root->left);
        cout<<root->data<<" ";
        zhongxu(root->right);
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
int main()
{
    int node[100];
    int n;
    cin>>n;
    cout<<"输入层序遍历："<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>node[i];
    }
    int i=0;
    treenode *root=buildtree(node,i,n);
    couttree(root);
    cout<<endl;
    zhongxu(root);
    cout<<endl;
    houxu(root);
}