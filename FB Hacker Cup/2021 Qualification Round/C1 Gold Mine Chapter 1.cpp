#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB emplace_back
#define MP make_pair
#define MT make_tuple

#define REP(i,a,b) for (ll i = (a); i < (b); ++i)
#define RREP(i,a,b) for (ll i = (a); i > (b); --i)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define FILE_IN freopen("input.txt", "r", stdin);
#define FILE_OUT freopen("output.txt", "w", stdout);
#define TESTCASES ll tt; cin >> tt; while (tt--)
#define TESTCASES1 ll tt; cin >> tt; REP(ttt, 1, tt + 1)

#define NEG_INF (-LLONG_MAX)
#define FLOAT_EQ(a, b) (abs((a) - (b)) < 1e-9)
#define NEWL "\n";

typedef long long ll;
//typedef __int128_t lll;
//typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<int> vl;
typedef vector<vi> vvl;

int n;
ll x, y;
vl g, mg;
vvl adj;

void dfs(int u, int v) {
	for (auto z : adj[u]) {
		if (z == v) continue;
		if (mg[z] == 0)
			dfs(z, u);
		mg[u] = max(mg[u], mg[z]);
	}
	mg[u] += g[u];
}

int main() {
	FAST_IO
	FILE_IN
	FILE_OUT

	TESTCASES1 {
		cin >> n;
		if (n == 1) {
			ll temp;
			cin >> temp;
			cout << "Case #" << ttt << ": " << temp << "\n";
			continue;
		}

		g.clear();
		mg.clear();
		adj.clear();

		REP(i, 0, n) {
			cin >> x;
			g.PB(x);
			mg.PB(0);
			adj.PB(vl());
		}
		REP(i, 0, n - 1) {
			cin >> x >> y;
			--x;
			--y;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		ll acc = g[0], root = 0, old = 0, next;
		if (adj[0].size() == 1) {
			root = adj[root][0];
			acc += g[root];
			while (adj[root].size() == 2) {
				next = (adj[root][0] == old) ? adj[root][1] : adj[root][0];
				acc += g[next];

				old = root;
				root = next;
			}
		}
		dfs(root, old);

		ll max1 = 0, max2 = 0;
		if (root == 0) {
			for (auto u : adj[root]) {
				if (mg[u] >= max1) {
					max2 = max1;
					max1 = mg[u];
				}
				else if (mg[u] > max2) {
					max2 = mg[u];
				}
			}
		}
		else {
			for (auto u : adj[root]) {
				if (u == old) continue;
				if (mg[u] > max1)
					max1 = mg[u];
			}
		}
		cout << "Case #" << ttt << ": " << max1 + max2 + acc << "\n";
	}

	cout << flush;
}
