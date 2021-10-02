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

struct PairHash {
	size_t operator()(const std::pair<int, int>& v) const {
		std::hash<int> hasher;
		size_t seed = 0;
		seed ^= hasher(v.F) + 0x9e3779b9 + (seed<<6) + (seed>>2);
		seed ^= hasher(v.S) + 0x9e3779b9 + (seed<<6) + (seed>>2);
		return seed;
	}
};


int main() {
	FAST_IO
//	FILE_IN
//	FILE_OUT

//	TESTCASES {
	int n, a, b;
	cin >> n >> a >> b;
	int d[n];
	REP(i, 0, n) cin >> d[i];

	unordered_map<pi, int, PairHash> pos[n];

	pos[0][{d[0], 0}] = 0;
	pos[0][{-d[0], 0}] = 1;
	pos[0][{0, d[0]}] = 2;
	pos[0][{0, -d[0]}] = 3;

	REP(i, 1, n) {
		for (auto p : pos[i - 1]) {
			pos[i][{p.F.F + d[i], p.F.S}] = 0;
			pos[i][{p.F.F - d[i], p.F.S}] = 1;
			pos[i][{p.F.F, p.F.S + d[i]}] = 2;
			pos[i][{p.F.F, p.F.S - d[i]}] = 3;
		}
	}
	if (pos[n - 1].count({a, b})) {
		cout << "Yes\n";
		string path;
		pi cur_pos = {a, b};
		RREP(i, n - 1, -1) {
			int dir = pos[i][cur_pos];
			if (dir == 0) {
				cur_pos = {cur_pos.F - d[i], cur_pos.S};
				path.push_back('R');
			}
			else if (dir == 1) {
				cur_pos = {cur_pos.F + d[i], cur_pos.S};
				path.push_back('L');
			}
			else if (dir == 2) {
				cur_pos = {cur_pos.F, cur_pos.S - d[i]};
				path.push_back('U');
			}
			else {
				cur_pos = {cur_pos.F, cur_pos.S + d[i]};
				path.push_back('D');
			}
		}
		reverse(all(path));
		cout << path;
	}
	else {
		cout << "No";
	}

//	}

	cout << flush;
}
