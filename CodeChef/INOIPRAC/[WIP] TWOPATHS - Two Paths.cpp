#pragma GCC optimize("O3,unroll-loops")
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


//#define NEG_INF -1000000000001
long long grid[1000][1000], dp_min[1000][1000][20], dp_max[1000][1000][20];


ll compute_max(int r, int c, int k) {
	if (r == 0) return grid[0][c];
	if (dp_max[r][c][k] != NEG_INF) return dp_max[r][c][k];

	if (k == 0 || c == 0) {
		long long temp = 0, row = r;
		while (row >= 0) {
			temp += grid[row][c];
			row--;
		}
		return dp_max[r][c][k] = temp;
	}
	return dp_max[r][c][k] = grid[r][c] + max(compute_max(r - 1, c, k), compute_max(r - 1, c - 1, k - 1));
}

ll compute_min(int r, int c, int k) {
	if (c == 0) return dp_min[r][c][k] = 0;
	if (r == 0) return grid[0][c - 1];
	if (dp_min[r][c][k] != NEG_INF) return dp_min[r][c][k];

	if (k == 0) {
		long long temp = 0, row = r;
		while (row >= 0) {
			temp += grid[row][c - 1];
			row--;
		}
		return dp_min[r][c][k] = temp;
	}
	return dp_min[r][c][k] = grid[r][c - 1] + min(compute_min(r - 1, c, k), compute_min(r - 1, c - 1, k - 1));
}


int main() {
	FAST_IO
//	FILE_IN
//	FILE_OUT

	TESTCASES {
		int N, M, K;
		long long m;
		cin >> N >> M >> K;

		for (int i = 0; i < N; i++) {
			cin >> grid[i][0];
			for (int j = 1; j < M; j++) {
				cin >> grid[i][j];
				grid[i][j] += grid[i][j - 1];
			}
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				for (int k = 0; k <= K; k++) {
					dp_min[r][c][k] = NEG_INF;
					dp_max[r][c][k] = NEG_INF;
				}
			}
		}
		for (int j = 0; j < M; j++) {
			compute_min(N - 1, j, K);
			compute_max(N - 1, j, K);
		}
		m = NEG_INF;
		for (int i = 0; i < M - K - 1; i++) {
			for (int j = i + K + 1; j < M; j++) {
				m = max(m, dp_max[N - 1][j][K] - dp_min[N - 1][i][K]);
			}
		}
		cout << m << '\n';
	}

	cout << flush;
}
