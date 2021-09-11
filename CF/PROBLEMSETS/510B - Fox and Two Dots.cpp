//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB emplace_back
#define MP make_pair
#define MT make_tuple

#define REP(i,a,b) for (ll i = (a); i < (b); ++i)
#define RREP(i,a,b) for (ll i = (a); i > (b); --i)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define FILE_IN freopen("input.txt", "r", stdin);
#define FILE_OUT freopen("output.txt", "w", stdout);
#define TESTCASES ll tt; cin >> tt; while (tt--)
#define TESTCASES1 ll tt; cin >> tt; REP(ttt, 1, tt + 1)

#define NEG_INF (-LLONG_MAX)
#define FLOAT_EQ(a, b) (abs((a) - (b)) < 1e-9)
#define NEWL "\n";

typedef long long ll;
//typedef __int128_t lll;
//typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<int> vl;
typedef vector<vi> vvl;

int n, m;
char a[51][51];
int vis[51][51];
int dfs(int x1, int y1, int x2, int y2) {
	vis[x1][y1] = 1;
	pi moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	for (auto move : moves) {
		int x = x1 + move.F, y = y1 + move.S;
		if (x == x2 && y == y2) continue;
		if (x < 0 || x >= n) continue;
		if (y < 0 || y >= m) continue;
		if (a[x][y] != a[x1][y1]) continue;

		if (vis[x][y]) return 1;
		if (dfs(x, y, x1, y1)) return 1;
	}
	return 0;
}

int main() {
	FAST_IO

//	TESTCASES {
	cin >> n >> m;
	REP(i, 0, n) REP(j, 0, m) cin >> a[i][j];
	REP(i, 0, n) REP(j, 0, m) vis[i][j] = 0;
	int flag = 0;
	REP(i, 0, n) {
		REP(j, 0, m) {
			if (!vis[i][j]) {
				int test = dfs(i, j, -1, -1);
				if (test) {
					cout << "Yes\n";
					flag = 1;
					break;
				}
			}
		}
		if (flag) break;
	}
	if (!flag) cout << "No\n";


//	}

	cout << flush;
}
