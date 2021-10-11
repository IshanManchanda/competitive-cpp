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

string m;
bool vis[7][7];
const int r[] = {0, 1, 0, -1}, c[] = {-1, 0, 1, 0};

int solve(int s, int x, int y) {
	if (x == 0 && y == 6) {
		if (s == 48) return 1;
		return 0;
	}
	if (s == 48) return 0;

	if ((x == 6 || x == 0 || (vis[x - 1][y] && vis[x + 1][y])))
		if (y > 1 && y < 6 && !vis[x][y - 1] && !vis[x][y + 1])
			return 0;
	if ((y == 6 || y == 0 || (vis[x][y - 1] && vis[x][y + 1])))
		if (x > 1 && x < 6 && !vis[x - 1][y] && !vis[x + 1][y])
			return 0;

	if (m[s] == '?') {
		int a = 0;
		REP(i, 0, 4) {
			int x1 = x + r[i], y1 = y + c[i];
			if (x1 < 0 || x1 > 6 || y1 < 0 || y1 > 6 || vis[x1][y1]) continue;
			vis[x1][y1] = true;
			a += solve(s + 1, x1, y1);
			vis[x1][y1] = false;
		}
		return a;
	}

	else if (m[s] == 'D') y++;
	else if (m[s] == 'U') y--;
	else if (m[s] == 'R') x++;
	else x--;
	if (x < 0 || x > 6 || y < 0 || y > 6 || vis[x][y]) return 0;
	vis[x][y] = true;
	int a = solve(s + 1, x, y);
	vis[x][y] = false;
	return a;
}

int main() {
	FAST_IO
//	FILE_IN
//	FILE_OUT

//	TESTCASES {
	cin >> m;
	vis[0][0] = 1;
	cout << solve(0, 0, 0) << flush;
//	}

//	cout << flush;
}
