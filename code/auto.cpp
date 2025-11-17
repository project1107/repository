#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> p(10);
	for (int i = 0; i < 10; i++) {
		//int a;
		cin>>p[i];
		//cin >> a;
		//p.push_back(a);
	}
	//for (int n : p)//使用副本，会无法操作改变原数据
	for (auto& n:p)//对p中元素直接引用
	{
		cout << n << endl;
	}

}
