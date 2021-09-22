//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")

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
//#define MOD (1'000'000'007)
//#define MOD_SUM(a, b) ((a) + (b) >= MOD) ? ((a) + (b) - MOD) : ((a) + (b))
#define NEWL "\n";

typedef long long ll;
//typedef __int128_t lll;
//typedef long double ld;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vi> vvl;


int main() {
	FAST_IO

//	TESTCASES {
	int n, k;
	cin >> n;

//	ll dp[n + 1][10];
//	REP(i, 0, n + 1) REP(j, 0, 10) dp[i][j] = -1;
//	dp[0][0] = 0;
	ll cur[10], next[10];
	REP(i, 1, 10) cur[i] = next[i] = -1;
	cur[0] = next[0] = 0;

	REP(i, 0, n) {
		cin >> k;
		int c[k], d[k];
		REP(j, 0, k) cin >> c[j] >> d[j];

		int idx3, idx2, idx1_1, idx1_2, idx1_3;
		idx3 = idx2 = idx1_1 = idx1_2 = idx1_3 = -1;
		REP(j, 0, k) {
			if (c[j] == 3) {
				if (idx3 == -1 || d[j] > d[idx3]) idx3 = j;
			} else if (c[j] == 2) {
				if (idx2 == -1 || d[j] > d[idx2]) idx2 = j;
			} else {
				if (idx1_1 == -1 || d[j] > d[idx1_1]) {
					idx1_3 = idx1_2;
					idx1_2 = idx1_1;
					idx1_1 = j;
				} else if (idx1_2 == -1 || d[j] > d[idx1_2]) {
					idx1_3 = idx1_2;
					idx1_2 = j;
				} else if (idx1_3 == -1 || d[j] > d[idx1_3]) {
					idx1_3 = j;
				}
			}
		}

		copy(next, next + 10, cur);

		int idxm = idx3, idxm2 = idx1_1;
		if (idxm == -1 || (idx2 != -1 && d[idx2] > d[idxm])) idxm = idx2;
		if (idxm == -1 || (idx1_1 != -1 && d[idx1_1] > d[idxm])) idxm = idx1_1;
		if (idxm == -1) continue;

		REP(j, 0, 9) {
			if (cur[j] == -1) continue;
			next[j + 1] = max(next[j + 1], cur[j] + d[idxm]);
		}
		// j = 9
		if (cur[9] != -1)
			next[0] = max(next[0], cur[9] + 2 * d[idxm]);

		idxm = idx2;
		if (idxm == -1 || (idx1_2 != -1 && d[idx1_2] > d[idxm])) idxm = idx1_2;
		if (idxm == -1 || idxm2 == -1) continue;

		REP(j, 0, 8) {
			if (cur[j] == -1) continue;
			next[j + 2] = max(next[j + 2], cur[j] + d[idxm] + d[idxm2]);
		}
		// j = 8
		REP(j, 8, 10) {
			if (cur[j] == -1) continue;
			next[j - 8] = max(next[j - 8], cur[j] + d[idxm] + d[idxm2] + max(d[idxm], d[idxm2]));
		}

		if (idx1_2 == -1 || idx1_3 == -1) continue;

		REP(j, 0, 7) {
			if (cur[j] == -1) continue;
			next[j + 3] = max(next[j + 3], cur[j] + d[idx1_1] + d[idx1_2] + d[idx1_3]);
		}
		// j = 7
		REP(j, 7, 10) {
			if (cur[j] == -1) continue;
			next[j - 7] = max(next[j - 7], cur[j] + d[idx1_1] + d[idx1_2] + d[idx1_3] + max({d[idx1_1], d[idx1_2], d[idx1_3]}));
		}
	}

	cout << *max_element(next, next + 10);
//	}

	cout << flush;
}
