//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC optimize("O2,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
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

int main() {
	FAST_IO
//	FILE_IN
//	FILE_OUT

	TESTCASES {
		int n, q;
		cin >> n;
		int a[n];
		cinai(a, n);
		cin >> q;

		pair<pi, pi> qs[q];
		REP(i, 0, q) {
			cin >> qs[i].F.S >> qs[i].F.F;
			qs[i].S.F = i;
			qs[i].S.S = 0;
		}
		sort(qs, qs + q);

		int qi = 0, k = 0;
		int m1x[n + 1], m2x[n + 1];
		int *m1 = m1x, *m2 = m2x;
		REP(i, 0, n + 1) m1[i] = m2[i] = 0;
		REP(i, 0, n) {
			m1[a[i]]++;
		}
		while (qi < q) {
			while (k < qs[qi].F.F) {
				REP (i, 0, n) {
					a[i] = m1[a[i]];
				}
				REP(i, 0, n + 1) m2[i] = 0;
				REP(i, 0, n + 1) {
					m2[m1[i]] += m1[i];
				}
				k++;

				int flag = 0;
				REP(i, 0, n) {
					if (m1[i] != m2[i]) {
						flag = 1;
						break;
					}
				}
				if (!flag) break;
				swap(m1, m2);
			}
			// store ans
			qs[qi].S.S = a[qs[qi].F.S - 1];
			qi++;
		}
		while (qi < q) {
			qs[qi].S.S = a[qs[qi].F.S - 1];
			qi++;
		}

		sort(qs, qs + q, [] (pair<pi, pi> x, pair<pi, pi> y) {
			return x.S.F < y.S.F;
		});
		REP(i, 0, q) {
			cout << qs[i].S.S << "\n";
		}
	}

	cout << flush;
}
