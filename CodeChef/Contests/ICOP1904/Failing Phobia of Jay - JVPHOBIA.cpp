#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m , s, k, a, b, c;
	queue<int> q;
	cin >> n >> m;

	vector<int> adj[n], str[n];
	bool visited[n];
	for (int i = 0; i < n; i++) visited[i] = false;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		a--; b--;
		adj[a].emplace_back(b);
		str[a].emplace_back(c);
		adj[b].emplace_back(a);
		str[b].emplace_back(c);
	}

	c = 0;
	cin >> k >> s;
	for (int i = 0; i < k; ++i) {
		cin >> a;
		a--;
		if (!visited[a]) {
			visited[a] = true;
			c++;
			q.push(a);

			while (!q.empty()) {
				a = q.front();
				q.pop();
				for (int j = 0; j < adj[a].size(); ++j) {
					if (!visited[adj[a][j]] && str[a][j] <= s) {
						visited[adj[a][j]] = true;
						c++;
						q.push(adj[a][j]);
					}
				}
			}
		}
	}
	cout << c << endl;
}
