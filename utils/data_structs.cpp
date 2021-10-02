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

#define REP(i,a,b) for (ll i = (a); i < (b); ++i)
#define RREP(i,a,b) for (ll i = (a); i > (b); --i)

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

typedef long long ll;
//typedef __int128_t lll;
//typedef long double ld;
typedef pair<int,int> pi;
typedef tuple<int, int, int> ti;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vi> vvl;


/* ************************************ */


// Use to hash a vector. Syntax: unordered_set<vi, VectorHash> my_set;
struct VectorHash {
	size_t operator()(const std::vector<int>& v) const {
		std::hash<int> hasher;
		size_t seed = 0;
		for (int i : v) {
			seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
		}
		return seed;
	}
};


// Use to hash a pair of ints. Syntax: unordered_map<pi, int, PairHash> my_map;
struct PairHash {
	size_t operator()(const std::pair<int, int>& p) const {
		std::hash<int> hasher;
		size_t seed = 0;
		seed ^= hasher(p.F) + 0x9e3779b9 + (seed<<6) + (seed>>2);
		seed ^= hasher(p.S) + 0x9e3779b9 + (seed<<6) + (seed>>2);
		return seed;
	}
};


/* ************************************ */


int main() {
	FAST_IO

//	TESTCASES {
//	}
	cout << flush;
}
