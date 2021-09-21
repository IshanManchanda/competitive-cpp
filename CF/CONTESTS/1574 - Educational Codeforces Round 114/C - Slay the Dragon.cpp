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


int main() {
	FAST_IO

//	TESTCASES {

	int n, m;
	cin >> n;
	ll a[n], s = 0;
	REP(i, 0, n) {
		cin >> a[i];
		s += a[i];
	}
	cin >> m;
	ll b[m], c[m];
	REP(i, 0, m) cin >> b[i] >> c[i];

	sort(a, a+n);
	ll coins;
	REP(i, 0, m) {
		int pos = lower_bound(a, a+n, b[i]) - a;

		if (pos == n)
			coins = b[i] - a[n - 1] + max(0ll, c[i] + a[n - 1] - s);
		else {
			if ((c[i] + a[pos] - s) > 0 && pos) {
				coins = b[i] - a[pos - 1] + max(0ll, c[i] + a[pos - 1] - s);
				coins = min(coins, c[i] + a[pos] - s);
			}
			else coins = max(0ll, c[i] + a[pos] - s);
		}
		cout << coins << NEWL;
	}


//	}

	cout << flush;
}
