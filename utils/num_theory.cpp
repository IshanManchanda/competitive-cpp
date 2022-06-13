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


// Prime factors of all numbers from 2 to MAXN
#define MAXN ((int) 1.5e7 + 7)
int spf[MAXN];  // Smallest Prime Factor

void sieve() {
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++) spf[i] = i;
	for (int i = 4; i < MAXN; i += 2) spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++)
		if (spf[i] == i)
			for (int j = i * i; j < MAXN; j += i)
				if (spf[j] == j) spf[j] = i;
}


// x^y mod m in O(log y)
ll bin_exp_mod(ll x, ll y, ll m) {
    x %= m;
    ll ans = 1LL;
    while (y) {
        if (y & 1) ans = (ans * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return ans;
}
// recursive version
ll bin_exp_mod_recur(ll x, ll y, ll m) {
	if (y == 0) return 1;
	ll p = bin_exp_mod(x, y / 2, m);
	p = (p * p) % m;
	return (y % 2 == 0) ? p : (x * p) % m;
}

ll bin_exp(ll x, ll y) {
    ll ans = 1LL;
    while (y) {
        if (y & 1) ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}
// recursive version
ll bin_exp_recur(ll x, ll y) {
	if (y == 0) return 1;
	ll p = bin_exp_recur(x, y / 2);
	return (y % 2 == 0) ? p * p : x * p * p;
}

// Works when m is prime, use extended GCD otherwise
inline ll mod_inv(ll x, ll m) {
	return bin_exp_mod(x, m - 2, m);
}

// Factorial of all numbers from 2 to MAXN
#define MAXN ((int) 1.5e7 + 7)
ll fact[MAXN + 1];

void pre(ll m) {
    fact[0] = 1;
    for (ll i = 1; i <= MAXN; i++)
        fact[i] = (i * fact[i - 1]) % m;
}
inline ll nPr(ll n, ll r, ll m) {
    return (fact[n] * mod_inv(fact[n - r], m)) % m;
}
inline ll nCr(ll n, ll r, ll m) {
    return (nPr(n, r, m) * mod_inv(fact[r], m)) % m;
}
ll fact_mod_inv[MAXN + 1];
void pre_mod_inv(ll m) {
    fact_mod_inv[MAXN] = mod_inv(fact[MAXN], m);
    for (ll i = MAXN - 1; i > 0; i--)
        fact_mod_inv[i] = (fact_mod_inv[i + 1] * i) % m;
}

// XOR of all numbers from 1 to n
//inline ll xor1n(ll n) {
//    return (n % 4 == 0) ? n : ((n % 4 == 1) ? 1 : ((n % 4 == 2) ? n + 1 : 0));
//}
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
