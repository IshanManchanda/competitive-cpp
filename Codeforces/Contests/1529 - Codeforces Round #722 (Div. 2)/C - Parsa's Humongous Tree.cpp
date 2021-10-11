#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = (a); i < (b); ++i)

typedef long long ll;
//typedef __int128_t lll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define MAX 100001

int t, n;
ll l[MAX], r[MAX];
vvi adj;
ll dp[MAX][2];

ll dfs(int u, int b, int x=-1) {
	if (dp[u][b] != -1)
		return dp[u][b];

	dp[u][0] = dp[u][1] = 0;
	for (int v : adj[u]) {
		if (v == x) continue;
		dp[u][0] += max(
			abs(l[v] - l[u]) + dfs(v, 0, u),
			abs(r[v] - l[u]) + dfs(v, 1, u)
		);
		dp[u][1] += max(
			abs(l[v] - r[u]) + dfs(v, 0, u),
			abs(r[v] - r[u]) + dfs(v, 1, u)
		);
	}
	return dp[u][b];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	int u, v;
	while (t--) {
		cin >> n;
		adj = {};
		adj.push_back(vi());
		memset(dp, -1, sizeof dp[0][0] * 2 * (n + 1));

		REP(i, 1, n + 1) {
			cin >> l[i] >> r[i];
			adj.push_back(vi());
		}

		REP(i, 0, n - 1) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout << max(dfs(1, 0), dfs(1, 1)) << "\n";
	}
	cout << flush;
}
