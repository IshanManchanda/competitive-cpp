//#pragma GCC optimize("O3,unroll-loops")
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

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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


int main() {
	FAST_IO
//	FILE_IN
//	FILE_OUT

//	TESTCASES {
	int n;
	cin >> n;
	int a[n][3], dp[n][3];
	REP(i, 0, n) cin >> a[i][0] >> a[i][1] >> a[i][2];
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];

	REP(i, 1, n) {
		dp[i][0] = a[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = a[i][1] + max(dp[i - 1][2], dp[i - 1][0]);
		dp[i][2] = a[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << *max_element(dp[n - 1], dp[n - 1] + 3);
//	}

	cout << flush;
}
