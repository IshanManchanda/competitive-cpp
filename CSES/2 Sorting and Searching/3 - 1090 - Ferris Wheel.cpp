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

int main() {
	FAST_IO
//	FILE_IN
//	FILE_OUT

//	TESTCASES {
	int n, x;
	cin >> n >> x;
	int a[n], done[n];
	cinai(a, n);
	REP(i, 0, n) done[i] = 0;
	sort(a, a + n);

	int ans = 0, i = n - 1;
	while (i > 0) {
		if (done[i]) {
			i--;
			continue;
		}
		ans++;
		int idx = upper_bound(a, a + i, x - a[i]) - a;
		if (idx == i) idx--;
		while (idx >= 0) {
			if (!done[idx] && a[idx] + a[i] <= x) {
				done[idx] = 1;
				break;
			}
			idx--;
		}
		done[i] = 1;
		i--;
	}
	if (!done[0]) ans++;
	cout << ans;

    // Better alt:
    // For element i from the start, keep moving j backwards
    // (and incrementing ans)
    // until we find 2 that fit. In this case inc i and ans, dec j
//    for (int i = 0, j = n-1; i <= j; ++i, --j)
//    {
//        if (i == j) { ans++; continue; }
//        while (i < j && a[i] + a[j] > x) --j, ++ans;
//        ans++;
//    }

//	}

	cout << flush;
}
