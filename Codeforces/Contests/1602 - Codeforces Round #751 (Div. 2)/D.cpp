#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")
//#pragma GCC target("avx,avx2,fma")

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
#define NEWL "\n";

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

queue<pair<int, ll>> q;
int main() {
	FAST_IO
//	FILE_IN
//	FILE_OUT

//	TESTCASES {
	int n;
	cin >> n;
	int a[n], b[n];
	cinai(a, n);
	cinai(b, n);

	bool vis[n];
	REP(i, 0, n) vis[i] = false;
	vis[n - 1] = true;
	q.push({n - 1, 0LL});
	int reached = 0;

	int last[n], print[n];
	REP(i, 0, n) last[i] = print[i] = -1;
	stack<int> s;
	REP(i, 0, n - 1) s.push(i);

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.F - a[cur.F] == -1) {
			int x = cur.F;
			vi steps;
			while (last[x] != -1) {
				steps.PB(print[x]);
				x = last[x];
			}

			cout << cur.S + 1 << "\n";
			for (auto y = steps.rbegin(); y != steps.rend(); y++) {
				cout << *y << " ";
			}
			cout << "0\n";
			reached = 1;
			break;
		}

		while (!s.empty() && s.top() >= (cur.F - a[cur.F])) {
			int pos1 = s.top();
			int pos = pos1 + b[pos1];
			s.pop();

			if (!vis[pos]) {
				vis[pos] = true;
				last[pos] = cur.F;
				print[pos] = pos1 + 1;
				q.push({pos, cur.S + 1});
			}
		}

//		RREP(i, a[cur.F], -1) {
//			int pos = cur.F - i + b[cur.F - i];
//			if (!vis[pos]) {
//				vis[pos] = true;
//				last[pos] = cur.F;
//				print[pos] = cur.F - i + 1;
//				q.push({pos, cur.S + 1});
//			}
//		}
	}
	if (!reached) cout << "-1\n";
//	}

	cout << flush;
}
