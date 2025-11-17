#include <iostream>
#include <vector>
using namespace std;

int MAX_DEEP = 18;

long long temp[19] = {0}; // 显式初始化为 0

int getDeep(int n) {
	int res = 0;
	while (n > 0) {
		n /= 2;
		res++;
	}
	return res;
}

int main() {
	int n, i;
	cin >> n;
	int a[100001];
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		temp[getDeep(i)] += a[i];
	}

	int maxnum = -1000000000; // 初始化为一个非常小的数，以处理负权值
	vector<int> resDeep; // 使用动态数组存储最大权值和的深度

	for (int j = 1; j <= MAX_DEEP; j++) { // 遍历所有可能的深度
		if (temp[j] > maxnum) {
			maxnum = temp[j];
			resDeep.clear(); // 清空之前的记录
			resDeep.push_back(j);
		} else if (temp[j] == maxnum) { // 记录相同的层数
			resDeep.push_back(j);
		}
	}

	cout << maxnum << endl;
	for (i = 0; i < resDeep.size(); i++) {
		if (i == 0) {
			cout << resDeep[i]; // 第一个数字前面不加空格
		} else {
			cout << " " << resDeep[i]; // 其他数字前面加空格
		}
	}
	cout << endl; // 输出换行符

	return 0;
}