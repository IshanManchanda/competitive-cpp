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
//#define MOD_SUM(a, b) ((a) + (b) >= MOD) ? ((a) + (b) - MOD) : ((a) + (b))
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

static inline ll mod(ll a) {
	if (a >= MOD) a -= MOD;
	if (a >= MOD) a %= MOD;
	return (a < 0) ? (a % MOD) + MOD : a;
}

static inline ll mod2(ll a) {
	a *= 2;
	return (a >= MOD) ? a - MOD : a;
}

//static inline ll mod_sum(ll a, ll b) {
//	ll c = a + b;
//	return (c >= MOD) ? c - MOD : c;
//}

int main() {
	FAST_IO
	FILE_IN
	FILE_OUT

	TESTCASES1 {
		int k;
		string u;
		cin >> k >> u;
		ll ans = 0, lhs = 0, rhs = 0, cnt = 0, n = 0;

		REP(i, 0, k) {
			if (u[i] == '.')
				n = mod2(n);
			else ++n;
		}

		char first = 'F', last = 'F';
		ll last_pos = -1, first_pos = n, j = 0;

		REP(i, 0, k) {
			++j;
			if (u[i] == 'F') continue;
			if (first == 'F' && u[i] != '.') {
				first = u[i];
				first_pos = j - 1;
			}

			if (u[i] == 'X') {
				// j = length, use j - 1
				if (last == 'O') {
					ans = (ans + ((last_pos + 1) * mod(n - j + 1)) % MOD) % MOD;
					lhs = (lhs + last_pos + 1) % MOD;
					rhs = (rhs + mod(n - j + 1)) % MOD;
					cnt = (cnt + 1) % MOD;
//					ans = mod(ans + mod((last_pos + 1) * (n - j + 1)));
//					lhs = mod(lhs + last_pos + 1);
//					rhs = mod(rhs + n - j + 1);
//					++cnt;
				}
				last = 'X';
				last_pos = j - 1;
			}

			else if (u[i] == 'O') {
				// j = length, use j - 1
				if (last == 'X') {
					ans = (ans + ((last_pos + 1) * mod(n - j + 1)) % MOD) % MOD;
					lhs = (lhs + last_pos + 1) % MOD;
					rhs = (rhs + mod(n - j + 1)) % MOD;
					cnt = (cnt + 1) % MOD;
//					ans = mod(ans + mod((last_pos + 1) * (n - j + 1)));
//					lhs = mod(lhs + last_pos + 1);
//					rhs = mod(rhs + n - j + 1);
//					++cnt;
				}
				last = 'O';
				last_pos = j - 1;
			}

			else {
				// j = length, use j - 1
				--j;
//				ans = mod2(ans);
//				ans = mod(ans + j * (rhs - lhs - cnt * j));
//				lhs = mod2(lhs);
//				lhs = mod(lhs + cnt * j);
//				rhs = mod2(rhs);
//				rhs = mod(rhs - cnt * j);
//				cnt = mod2(cnt);

				ans = (ans * 2) % MOD;
				ll mu2 = (cnt * j) % MOD;
				ll mu = (rhs - lhs - mu2) % MOD;
				mu = (mu * j) % MOD;
				ans = (ans + mu) % MOD;
				ans = (ans < 0) ? ans + MOD : ans;

				lhs = (lhs * 2) % MOD;
				lhs = (lhs + mu2) % MOD;
				rhs = (rhs * 2) % MOD;
				rhs = (rhs - mu2) % MOD;
				cnt = (cnt * 2) % MOD;

				if ((first == 'O' && last == 'X') || (first == 'X' && last == 'O')) {
					ans = (ans + ((last_pos + 1) * (n - j - first_pos)) % MOD) % MOD;
					rhs = (rhs + n - j - first_pos) % MOD;
					lhs = (lhs + last_pos + 1) % MOD;
					cnt = (cnt + 1) % MOD;
//					ans = mod(ans + mod((last_pos + 1) * (n - j - first_pos)));
//					rhs = mod(rhs + n - j - first_pos);
//					lhs = mod(lhs + last_pos + 1);
//					++cnt;
				}
//				last_pos = mod(last_pos + j);
//				j = mod2(j);
				last_pos = (last_pos + j) % MOD;
				j = (j * 2) % MOD;
			}
		}
		ans %= MOD;
		CASEOUT << ((ans < 0)? ans + MOD : ans) << "\n";
	}

	cout << flush;
}
