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
double dp[303][303][303];

double solve(int a, int b, int c) {
	if (a < 0 || b < 0 || c < 0) return 0;
	if (a + b + c == 0) return 0;
	if (dp[a][b][c] > 0) return dp[a][b][c];

	double ans = n + a * solve(a - 1, b, c) +
		b * solve(a + 1, b - 1, c) + c * solve(a, b + 1, c - 1);
	return dp[a][b][c] = ans / (a + b + c);
}

int main() {
	FAST_IO
//	FILE_IN
//	FILE_OUT

//	TESTCASES {
	cin >> n;
	int a[3] = {0}, x;
	REP(i, 0, n) {
		cin >> x;
		a[x - 1]++;
	}
	REP(i, 0, n + 1) REP(j, 0, n + 1) REP(k, 0, n + 1) dp[i][j][k] = -1.0;
	cout << setprecision(17) << fixed;
	cout << solve(a[0], a[1], a[2]) << endl;

//	}
	cout << flush;
}
