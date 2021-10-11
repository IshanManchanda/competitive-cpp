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


ll pow(ll x, ll y, ll m) {
	if (y == 0) return 1;
	ll p = pow(x, y / 2, m) % m;
	p = (p * p) % m;
	return (y % 2 == 0) ? p : (x * p) % m;
}

int main() {
	FAST_IO

	ll fact[200003];
	ll mod = 998244353;
	fact[0] = fact[1] = 1;
	REP(i, 2, 200002) {
		fact[i] = (i * fact[i - 1]) % mod;
	}

	TESTCASES {
		int n, m1 = -1, m2 = -1, temp, m2_ctr = 1;
		cin >> n;
		REP(i, 0, n) {
			cin >> temp;
			if (temp >= m1) {
				if (m2 == m1)
					++m2_ctr;
				else
					m2_ctr = 1;
				m2 = m1;
				m1 = temp;
			}
			else if (temp > m2) {
				m2 = temp;
				m2_ctr = 1;
			}
			else if (temp == m2) {
				++m2_ctr;
			}
		}

		if (m1 - m2 >= 2) {
			cout << "0\n";
		}
		else if (m1 - m2 == 1) {
			cout << (((fact[n] * m2_ctr) % mod) * pow(m2_ctr + 1, mod - 2, mod)) % mod <<"\n";
		}
		else {
			cout << fact[n] << "\n";
		}
	}

	cout << flush;
}
