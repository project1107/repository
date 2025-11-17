#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &out, int visited[]) {
	visited[node] = 1;
	out.push_back(node);
	for (int neighbor : adj[node]) {
		if (!visited[neighbor])
			dfs(neighbor, adj, out, visited);
	}
}

int main() {
	int N, M, S;
	cin >> N >> M >> S;
	vector<int> adj[1000];
	int visited[1000] = {0};
	vector<int> out;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 0; i < N; i++)
		sort(adj[i].begin(), adj[i].end());
	dfs(S, adj, out, visited);
	for (int num : out)
		cout << num << " ";
	cout << endl;
	bool p = true;
	for (int i = 1; i <= N; i++)
		if (!visited[i]) {
			p = false;
			break;
		}
	if (!p)
		cout << "false";
}
