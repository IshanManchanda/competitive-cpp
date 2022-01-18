#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC optimize("O2,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

#define PB emplace_back
#define MP make_pair
#define MT make_tuple

#define REP(i, a, b) for (ll i = (a); i < (b); ++i)
#define RREP(i, a, b) for (ll i = (a); i > (b); --i)

#define cinai(a, n) REP(ii, 0, (n)) cin >> (a)[ii];

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define FILE_IN freopen("input.txt", "r", stdin);
#define FILE_OUT freopen("output.txt", "w", stdout);

#define TESTCASES ll tt; cin >> tt; while (tt--)
#define TESTCASES1 ll tt; cin >> tt; REP(ttt, 1, tt + 1)
#define CASEOUT cout << "Case #" << ttt << ": "

#define NEG_INF (-LLONG_MAX)
#define FLOAT_EQ(a, b) (abs((a) - (b)) < 1e-9)
#define MOD (1'000'000'007)
//#define MOD_SUM(a, b) ((a) + (b) >= MOD) ? ((a) + (b) - MOD) : ((a) + (b))
#define newl "\n"

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag,
//	tree_order_statistics_node_update> indexed_set;
/* find_by_order(k) and order_of_key(x) */

typedef long long ll;
//typedef __int128_t lll;
//typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vi> vvl;

int n, T = 0;
vi par, t1, t2, dep;

void dfs(int u, int v, vi adj[], int d) {
	dep[u] = d;
	t1[u] = T++;
	for (auto x : adj[u]) {
		if (x == v) continue;
		par[x] = u;
		dfs(x, u, adj, d + 1);
	}
	t2[u] = T++;
}

int main() {
	FAST_IO
//	FILE_IN
//	FILE_OUT

//	TESTCASES {
	int m, u, v, k;
	cin >> n >> m;
	vi adj[n];
	REP(i, 0, n - 1) {
		cin >> u >> v;
		adj[u - 1].PB(v - 1);
		adj[v - 1].PB(u - 1);
	}
	par.resize(n);
	t1.resize(n);
	t2.resize(n);
	dep.resize(n);
	par[0] = 0;
	dfs(0, -1, adj, 0);

	REP(i, 0, m) {
		cin >> k;
		int a[k];
		cinai(a, k);

		int l = a[0] - 1;
		for (auto x : a) if (dep[l] < dep[x - 1]) l = x - 1;
		bool flag = true;
		for (auto x : a) {
			if (x - 1 == l) continue;
			flag &= t1[par[x - 1]] <= t1[l] && t2[l] <= t2[par[x - 1]];
		}
		cout << (flag ? "YES" : "NO") << newl;
	}
//	}
	cout << flush;
}
