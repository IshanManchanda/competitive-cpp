#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (ll i = (a); i < (b); ++i)
#define RREP(i,a,b) for (ll i = (a); i > (b); --i)

#define NEG_INF (-LLONG_MAX)

typedef long long ll;
//typedef __int128_t lll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		vi adj[n];
		int x, y;

		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			--x;
			--y;
			adj[x].PB(y);
			if (x == y) continue;
			adj[y].PB(x);
		}

		int paths[n];
		for (int i = 0; i < n; ++i)
			paths[i] = 0;

		paths[0] = 1;
		priority_queue<int> pq;
		pq.push(0);
		while (!pq.empty()) {
			int u = pq.top();
			pq.pop();

			for (int v: adj[u]) {
				if (paths[v] )
			}
		}

	}

	cout << flush;
}
