#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct tree {
    tree *left;
    tree *right;
    int node;
    tree(int x) : node(x), left(nullptr), right(nullptr) {}
};
tree* buildtree(int& n,vector<int>& zhongxu,vector<int>& houxu, int inbegin, int inend) {
    if (inbegin > inend) {
        return nullptr;
    }
    tree* root = new tree(houxu[n]);
    int inroot = find(zhongxu.begin() + inbegin, zhongxu.begin() + inend + 1, houxu[n]) - zhongxu.begin();
    n--;
    root->right = buildtree(n, zhongxu, houxu, inroot + 1, inend);
    root->left = buildtree(n, zhongxu, houxu, inbegin, inroot - 1);
    return root;
}
void view(tree* root,vector<int>& Left,vector<int>& Right)
{
    if(!root)
    {
        return;
    }
    queue<tree*> nodes;
    nodes.push(root);
    while(!nodes.empty())
    {
        int count=nodes.size();
        for(int i=0;i<count;i++)
        {
            tree* r=nodes.front();
            nodes.pop();
            if(i==0)
            {
                Left.push_back(r->node);
            }
            if(i==count-1)
            {
                Right.push_back(r->node);
            }
            if(r->left)
            nodes.push(r->left);
            if(r->right)
            nodes.push(r->right);
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> zhongxu, houxu;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        zhongxu.push_back(p);
    }
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        houxu.push_back(p);
    }
    int a=n-1;
    tree* tree1 = buildtree(a, zhongxu, houxu, 0, n - 1);
    // if (tree1) {
    //     cout << tree1->node << endl;
    // } else {
    //     cout << "No valid tree" << endl;
    // }
    vector<int>Left,Right;
    view(tree1,Left,Right);
    for(int i=0;i<Right.size();i++)
    {
        if(i==0)
            cout<<"R:";
        cout<<" "<<Right[i];
    }
    cout<<endl;
    for(int i=0;i<Left.size();i++)
    {
        if(i==0)
            cout<<"L:";
        cout<<" "<<Left[i];
    }
    return 0;
}