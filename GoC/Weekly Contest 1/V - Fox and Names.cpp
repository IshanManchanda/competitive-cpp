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
#define newl "\n";

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

int n;
vi adj[26];
int vis[26];
stack<int> s1;

void dfs(int c) {
	vis[c] = 1;
	for (auto c1 : adj[c]) {
		if (!vis[c1]) dfs(c1);
	}
	s1.push(c);
}

int bfs(int c) {
	vis[c] = 1;
	for (auto c1 : adj[c])
		if (vis[c1]) return 0;
	return 1;
}

int main() {
	FAST_IO
//	FILE_IN
//	FILE_OUT

//	TESTCASES {
	cin >> n;
	string s[n];
	REP(i, 0, n) cin >> s[i];

	int flag = 0;
	REP(i, 0, n - 1) {
		int l_min = min(s[i].length(), s[i + 1].length()), j = 0;
		for (; j < l_min && s[i][j] == s[i + 1][j]; ++j);
		if (j == l_min) {
			if (s[i].length() == l_min) continue;
			else {
				flag = 1;
				cout << "Impossible" << endl;
				break;
			}
		}
		adj[s[i][j] - 'a'].PB(s[i + 1][j] - 'a');
	}

	if (flag) return 0;

	REP(i, 0, 26) vis[i] = 0;
	REP(i, 0, 26) if (!vis[i]) dfs(i);

	REP(i, 0, 26) vis[i] = 0;
	queue<int> q;
	while (!s1.empty()) {
		if (!bfs(s1.top())) {
			flag = 1;
			cout << "Impossible" << endl;
			break;
		}
		q.push(s1.top());
		s1.pop();
	}

	if (flag) return 0;

	while (!q.empty()) {
		cout << (char) ('a' + q.front());
		q.pop();
	}
//	}
	cout << flush;
}
