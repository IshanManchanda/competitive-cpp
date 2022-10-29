//#pragma GCC optimize("O2,unroll-loops")
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

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag,
//	tree_order_statistics_node_update> indexed_set;
/* find_by_order(k) and order_of_key(x) */

typedef long long ll;
typedef unsigned long long ull;
//typedef __int128_t lll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll n, m;
vl t, z, y;

bool check(ll t1) {
    ll b = 0;
    REP(i, 0, n) {
        b += (t1 / (t[i] * z[i] + y[i])) * z[i];
        b += min(z[i], (t1 % (t[i] * z[i] + y[i])) / t[i]);
    }
    return b >= m;
}

int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(19);

//    TESTCASES {
//    }
    cin >> m >> n;
    t.resize(n);
    z.resize(n);
    y.resize(n);
    REP(i, 0, n) cin >> t[i] >> z[i] >> y[i];

    ll l = -1, r = (1ll << 33);
    while (r > l + 1) {
        ll c = (l + r) / 2;
        if (check(c)) r = c;
        else l = c;
    }
    if (check(l)) r = l;
    cout << r << NEWL;
    ll b = 0, c;
    REP(i, 0, n) {
        c = (r / (t[i] * z[i] + y[i])) * z[i];
        c += min(z[i], (r % (t[i] * z[i] + y[i])) / t[i]);
        b += c;
        if (b > m) {
            c -= b - m;
            b = m;
        }
        cout << c << " ";
    }

    cout << flush;
}
