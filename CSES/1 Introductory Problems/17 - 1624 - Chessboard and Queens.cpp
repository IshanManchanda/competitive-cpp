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

#define cinai(a, n) REP(ii, 0, (n)) cin >> (a)[ii];

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

char b[8][8];
// we solve column-wise. ctr holds ans
// ld and rd are the diagonal masks and r is the row mask
// also, these in global segment so initialized to 0
int ctr = 0, ld[15], rd[15], r[7];

void solve(int c) {
	if (c == 8) {
		ctr++;
		return;
	}
	REP(i, 0, 8) {
        // if not blocked and row free and both diags free
		if (b[i][c] == '.' && !r[i] && !ld[i + c] && !rd[i + 7 - c]) {
            // mark row and diags as taken
			r[i] = ld[i + c] = rd[i + 7 - c] = 1;
			solve(c + 1);  // recurse
            // unmark them as taken
			r[i] = ld[i + c] = rd[i + 7 - c] = 0;
		}
	}
}

int main() {
	FAST_IO
//	FILE_IN
//	FILE_OUT

//	TESTCASES {
	REP(i, 0, 8) REP(j, 0, 8) cin >> b[i][j];
	solve(0);
	cout << ctr;
//	}

	cout << flush;
}
