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


/* ************************************************************************** */


// x^y mod m in log(y) time
ll bin_exp_mod(ll x, ll y, ll m) {
	if (y == 0) return 1;
	ll p = bin_exp_mod(x, y / 2, m);
	p = (p * p) % m;
	return (y % 2 == 0) ? p : (x * p) % m;
}

ll bin_exp(ll x, ll y) {
	if (y == 0) return 1;
	ll p = bin_exp(x, y / 2);
	return (y % 2 == 0) ? p * p : x * p * p;
}

// Works when m is prime, use extended GCD otherwise
ll mod_inv(ll x, ll m) {
	return bin_exp_mod(x, m - 2, m);
}


// XOR of all numbers from 1 to n
ll xor1n(ll n) {
	if (n % 4 == 0) return n;
	if (n % 4 == 1) return 1;
	if (n % 4 == 2) return n + 1;
	return 0;
}


/* ************************************************************************** */

int main() {
	FAST_IO
	FILE_IN
	FILE_OUT

	TESTCASES {

	}

	cout << flush;
}
