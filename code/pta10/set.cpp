// #include <set>

// // 定义一个空的 set
// set<int> s;

// // 初始化一个 set
// set<int> s1 = {1, 2, 3, 4, 5};

// // 使用迭代器范围初始化
// int arr[] = {10, 20, 30, 40, 50};
// set<int> s2(arr, arr + 5);
// s.insert(10); // 插入元素 10
// s.insert(20); // 插入元素 20
// s.insert(10); // 重复插入 10，不会成功
// s.erase(10); // 删除元素 10
// s.erase(s.begin()); // 删除第一个元素
// if (s.find(20) != s.end()) {
//     cout << "Element 20 found" << endl;
// } else {
//     cout << "Element 20 not found" << endl;
// }
// for (auto it = s.begin(); it != s.end(); ++it) {
//     cout << *it << " ";
// }
// cout << endl;

// // 或者使用范围 for 循环
// for (const auto& elem : s) {
//     cout << elem << " ";
// }
// cout << endl;
// cout << "Size of set: " << s.size() << endl;
// s.clear();

#include<iostream>
#include<set>
using namespace std;
struct person
{
    int self=-1;
    char gender;
    int father=-1;
    int mother=-1;
}per[100000];
set<int> s;
int uns,n,k;
void ancestor(int id,int generation)
{
    if(generation>4)
    return;
    uns++;
    s.insert(id);
    if(per[id].father!=-1)
    {
        ancestor(per[id].father,generation+1);
    }
    if(per[id].mother!=-1)
    {
        ancestor(per[id].mother,generation+1);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int id;
        cin>>id>>per[id].gender>>per[id].father>>per[id].mother;
        if(per[id].father!=-1)
        {
            per[per[id].father].gender='M';
        }
        if(per[id].mother!=-1)
        {
            per[per[id].mother].gender='F';
        }
    }
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int s1,s2;
        cin>>s1>>s2;
        uns=0;
        s.clear();
        ancestor(s1,0);
        ancestor(s2,0);
        if(per[s1].gender==per[s2].gender)
        {
            cout<<"Never Mind"<<endl;
        }
        else if(uns!=s.size())
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
}