// #include <iostream>
// #include <unordered_map>

// int main() {
//     // 创建一个 unordered_map，键为 int，值为 string
//     std::unordered_map<int, std::string> myMap;

//     // 插入一些键值对
//     myMap[1] = "one";
//     myMap[2] = "two";
//     myMap[3] = "three";

//     // 打印所有元素
//     for (const auto& pair : myMap) {
//         std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
//     }

//     // 访问特定键的值
//     std::cout << "Value for key 2: " << myMap[2] << std::endl;

//     // 删除键为1的元素
//     myMap.erase(1);

//     // 再次打印所有元素
//     std::cout << "After erasing key 1:" << std::endl;
//     for (const auto& pair : myMap) {
//         std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
//     }

//     return 0;
// }
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
struct node
{
    string self;
    int num;
    string next;
};
int main()
{
    string start;
    int n;
    cin>>start>>n;
    unordered_map<string,node> lian;
    for(int i=0;i<n;i++)
    {
        node temp;
        cin>>temp.self>>temp.num>>temp.next;
        lian[temp.self]=temp;
    }
    unordered_map<int,bool> seen;
    string current=start;
    vector<node> out;
    vector<node> del;
    while(current!="-1")
    {
        const node& temp=lian[current];
        if(!seen[abs(temp.num)])
        {
            seen[abs(temp.num)]=true;
            out.push_back(temp);
        }
        else
        {
            del.push_back(temp);
        }
        current=temp.next;
    }
    for(int i=0;i<out.size();i++)
    {
        cout<<out[i].self<<" "<<out[i].num<<" ";
        if(i<out.size()-1)
        {
            cout<<out[i+1].self<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
    for(int i=0;i<del.size();i++)
    {
        cout<<del[i].self<<" "<<del[i].num<<" ";
        if(i<del.size()-1)
        {
            cout<<del[i+1].self<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
    
}