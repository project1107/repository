#include <bits/stdc++.h>
using namespace std;
 
 
const int N = 1e8 + 10;
const int M = -1e8 - 10;
int n, m, k, T;
 
signed main() {
	cin >> n;
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
	int max = M;
	int min = N;
	int lun = 0;
	while (n--) {
		lun++;
		int num, sum;
		scanf("%d", &num);
		if (num > max) {
			max = num;
		}
		if (num < min) {
			min = num;
		}
		if (left.empty() && right.empty()) {
			left.push(num);
		} else {
			if (left.size() > right.size()) {
				if (num >= left.top()) {
					right.push(num);
				} else {
					int temp = left.top();
					left.pop();
					left.push(num);
					right.push(temp);
				}
			} else {
				if (num <= right.top()) {
					left.push(num);
				} else {
					int temp = right.top();
					right.pop();
					right.push(num);
					left.push(temp);
				}
			}
		}
 
 
		//计算阶段
		if (lun != 1) {
			printf(" ");
		}
		if (lun % 2 == 1) {
			printf("%d", (min + max + left.top()) / 3);
		} else {
			printf("%d", (min + max + left.top() + right.top()) / 4);
		}
	}
	printf("\n");
}