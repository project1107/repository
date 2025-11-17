#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int maxheight = 0;
	int count = 1;
	stack<int> a, b;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	a.push(p[0]);
	for (int i = 1; i < n; i++) {
		if (p[i] < a.top()) {
			a.push(p[i]);
		} else if (b.empty() || p[i] > b.top()) {
			b.push(p[i]);
		} else {
			count++;
			int maxa = a.size();
			maxheight = max(maxheight, maxa);
			while (!a.empty())
				a.pop();
			while (!b.empty() && b.top() > p[i]) {
				a.push(b.top());
				b.pop();
			}
			a.push(p[i]);
		}
	}
	if (!b.empty()) {
		count++;
		int maxb = b.size();
		maxheight = max(maxheight, maxb);
	}
	cout << count << endl;
	cout << maxheight << endl;
}