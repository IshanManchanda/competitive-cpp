//#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")

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

int main() {
	FAST_IO

//	TESTCASES {
	int n, m, x;
	cin >> n;
	int c[n];
	vi a[n];
	REP(i, 0, n) {
		cin >> c[i];
		REP(j, 0, c[i]) {
			cin >> x;
			a[i].PB(x);
		}
	}
	cin >> m;
	if (m == 0) {
		REP(i, 0, n) {
			cout << c[i] << " ";
		}
		return 0;
	}

	vi temp(n);
	unordered_set<vi, VectorHash> bans, vis;
	REP(i, 0, m) {
		REP(j, 0, n) {
			cin >> temp[j];
			--temp[j];
		}
		bans.insert(temp);
	}

//	auto comp = [&n](vi v1, vi v2) {
//		REP(k, 0, n) {
//			if (v1[k] < v2[k]) return true;
//			if (v1[k] == v2[k]) continue;
//			break;
//		}
//		return false;
//	};
//	sort(b, b + m, comp);

	priority_queue<pair<int, vi>> pq;
	ll acc = 0;
	vi end;
	REP(i, 0, n) {
		acc += a[i][c[i] - 1];
		end.PB(c[i] - 1);
	}
	pq.push({acc, end});
//	REP(i, 0, n) {
//		if (!end[i]) continue;
//		--end[i];
//		pq.push({acc - a[i][c[i] - 1] + a[i][c[i] - 2], end});
//		++end[i];
//	}
	while (true) {
		auto elem = pq.top();
		pq.pop();

//		if (!binary_search(b, b + m, elem.S, comp)) {
		if (!bans.count(elem.S)) {
			REP(i, 0, n) {
				cout << elem.S[i] + 1 << " ";
			}
			break;
		}

		REP(i, 0, n) {
			if (!elem.S[i]) continue;
			--elem.S[i];
			if (!vis.count(elem.S)) {
				pq.push({elem.F - a[i][elem.S[i] + 1] + a[i][elem.S[i]], elem.S});
				vis.insert(elem.S);
			}
			++elem.S[i];
		}
	}

//	if (binary_search(a, a + n, val, comp)) {}


//	}
	cout << flush;
}
