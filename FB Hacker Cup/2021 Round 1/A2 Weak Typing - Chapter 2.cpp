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

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define FILE_IN freopen("input.txt", "r", stdin);
#define FILE_OUT freopen("output.txt", "w", stdout);

#define TESTCASES ll tt; cin >> tt; while (tt--)
#define TESTCASES1 ll tt; cin >> tt; REP(ttt, 1, tt + 1)
#define CASEOUT cout << "Case #" << ttt << ": "

#define NEG_INF (-LLONG_MAX)
#define FLOAT_EQ(a, b) (abs((a) - (b)) < 1e-9)
#define MOD (1'000'000'007)
#define MOD_SUM(a, b) ((a) + (b) >= MOD) ? ((a) + (b) - MOD) : ((a) + (b));
#define NEWL "\n";

typedef long long ll;
typedef unsigned long long ull;
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
	FILE_IN
	FILE_OUT

	TESTCASES1 {
		int n;
		string s;
		cin >> n >> s;

		char last = 'F';
		int last_pos = -1;
		ll ans = 0;
		REP(i, 0, n) {
			if (s[i] == 'F') continue;

			if ((s[i] == 'O' && last == 'X') || (s[i] == 'X' && last == 'O'))
				ans = (ans + (last_pos + 1) * (n - i)) % MOD;
			last = s[i];
			last_pos = i;
		}

		CASEOUT << ans << "\n";
	}

	cout << flush;
}
