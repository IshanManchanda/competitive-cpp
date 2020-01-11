// https://www.codechef.com/INOIPRAC/problems/INOI1302

// DFS Solution
#include <bits/stdc++.h>
using namespace std;

vector<long long> ids[301];
vector<long long> adj[301];
bool visited[301];
long long ans = 0;

void dfs(long long i) {
	if (visited[i]) {
		return;
	}
	visited[i] = true;
	++ans;
	for (auto j: adj[i]) {
		dfs(j);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, k, p, x;
	cin >> n >> k;

	for (auto i = 0; i < n; ++i) {
		visited[i] = false;
		cin >> p;
		while (p--) {
			cin >> x;
			ids[i].emplace_back(x);
		}
		sort(ids[i].begin(), ids[i].end());
	}

	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			if (i == j) continue;

			int l = 0, r = 0, c = 0;
			while (l < ids[i].size() && r < ids[j].size()) {

				if (ids[i][l] == ids[j][r]) {
					++c; ++l; ++r;
				} else if (ids[i][l] < ids[j][r])
					++l;
				else
					++r;

				if (c >= k) {
					adj[i].emplace_back(j);
					adj[j].emplace_back(i);
					break;
				}
			}
		}
	}
	dfs(0);
	cout << ans << endl;
}

// BFS Solution
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, k, p, x, ans = 0;
	cin >> n >> k;

	vector<long long> ids[n + 1];
	bool visited[n];
	for (auto i = 0; i < n; ++i) {
		visited[i] = false;
		cin >> p;
		while (p--) {
			cin >> x;
			ids[i].emplace_back(x);
		}
		sort(ids[i].begin(), ids[i].end());
	}

	vector<long long> adj[n];
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			if (i == j) continue;

			int l = 0, r = 0, c = 0;
			while (l < ids[i].size() && r < ids[j].size()) {

				if (ids[i][l] == ids[j][r]) {
					++c; ++l; ++r;
				} else if (ids[i][l] < ids[j][r])
					++l;
				else
					++r;

				if (c >= k) {
					adj[i].emplace_back(j);
					adj[j].emplace_back(i);
					break;
				}
			}
		}
	}

	queue<long long> q;
	q.push(0ll);
	visited[0] = true;
	while (!q.empty()) {
		ans++;
		p = q.front();
		q.pop();

		for (auto &i : adj[p]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}

	cout << ans << endl;
}
 */
