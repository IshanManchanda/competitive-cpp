#include <bits/stdc++.h>
using namespace std;


vector<int> adj[100000];
int levels[100000];


void assign(int u) {
	for (auto node : adj[u]) {
		levels[node] = levels[node] + 1;
		assign(node);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q, u, x, y;
	cin >> n >> q >> u;
	u--;
	levels[u] = 1;

	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	assign(u);
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
	}
}
