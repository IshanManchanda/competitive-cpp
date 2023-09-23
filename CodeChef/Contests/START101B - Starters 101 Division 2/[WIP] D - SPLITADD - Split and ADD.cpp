//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("tune=native")

#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

#define PB emplace_back
#define MP make_pair
#define MT make_tuple

#define REP(i, a, b) for (ll i = (a); i < (b); ++i)
#define RREP(i, a, b) for (ll i = (a); i > (b); --i)
#define cinai(a, n) REP(i, 0, n) cin >> a[i]
#define cinani(a, n) int n; cin >> n; int a[n]; cinai(a, n)
#define cinan(a, n) ll n; cin >> n; ll a[n]; cinai(a, n)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define FILE_IN freopen("input.txt", "r", stdin);
#define FILE_OUT freopen("output.txt", "w", stdout);

#define TESTCASES ll tt; cin >> tt; while (tt--)
#define TESTCASES1 ll tt; cin >> tt; REP(ttt, 1, tt + 1)
#define CASEOUT cout << "Case " << ttt << ": "

#define NEG_INF (-LLONG_MAX)
#define FLOAT_EQ(a, b) (abs((a) - (b)) < 1e-9)
#define MOD (1'000'000'007)
//#define MOD_SUM(a, b) ((a) + (b) >= MOD) ? ((a) + (b) - MOD) : ((a) + (b))
#define endl "\n";

#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ") ";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "] ";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "{ "; for (auto& it : p) os << it << " "; return os << "} ";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "] ";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "{ "; for (auto& it : p) os << it << " "; return os << "} ";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "{{ "; for (auto& it : p) os << it << " "; return os << "}} ";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "] ";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

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
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

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
// Works when m is prime, use extended GCD otherwise
inline ll mod_inv(ll x, ll m) {
    return bin_exp_mod(x, m - 2, m);
}

//map<pair<ll, pair<ll, ll>>, ll> m;

/*ll solve(ll n, ll l, ll r) {
//    if (m.find({n, {l, r}}) != m.end()) return m[{n, {l, r}}];
//    cout << n << " " << l << " " << r << endl;
    if (n == 2) {
        vi a({1, 2});
        ll ans = 0;
        REP(i, l, r + 1) ans += a[i - 1];
//        return m[{n, {l, r}}] = ans;
        return ans;
    }

    if (l == 1 && r == n) return (((n / 2) % MOD) * ((n + 1) % MOD)) % MOD;

    // if k is <= n / 2, it will be in left half and have
    // LSB set to 0
    // now we get some value from solve, push it left by 1 and don't set the bit
    // check if both L and R lie on the same side
    // both on left
    if (2 * r <= n) {
        ll ans = solve(n / 2, l, r);
        // each element needs to be * 2 - 1
        // * 2 direct, for -1 we need number of elems = r - l + 1
//        return m[{n, {l, r}}] = ((ans * 2) % MOD - (r - l + 1) + MOD) % MOD;
        return ((ans * 2) % MOD - (r - l + 1) + MOD) % MOD;
    }
    if (2 * l > n) {
        ll ans = solve(n / 2, l - n / 2, r - n / 2);
        // each element needs to be * 2
//        return m[{n, {l, r}}] = (ans * 2) % MOD;
        return (ans * 2) % MOD;
    }
    if (l == 1) {
        // l is 1, r is > n / 2
        // we should know the sum from 1 to n/2
        // some permutation of 1 -> n / 2
        // sum of this is n/2 * n/2+1 whole/2
        // and we perform our normal transform
        ll ans = (((n / 2) % MOD) * ((n / 2) % MOD)) % MOD;
        ans = (ans + solve(n, n / 2 + 1, r)) % MOD;
//        cout << l << " " << r << ": " << ans << endl;
        return ans;
//        return (ans + solve(n, n / 2 + 1, r)) % MOD;
    }
    if (r == n) {
        // n / 2 + 1 to n
        // 5 6 7 8
        // 2 4 6 8 -> 1 2 3 4
        // 2,3: 1 2 3 4
        // 1 3 2 4
        // if you do -1, then all are
        // 2 belongs to that part.
        // we should only have 2 + 4 = 6 in ans
        // ans = 4 * 2 = 8, wrong
        ll ans = (((n / 2) % MOD) * ((n / 2) % MOD)) % MOD;
        ans = ((ans + n / 2) % MOD + solve(n, l, n / 2)) % MOD;
//        cout << l << " " << r << ": " << ans << endl;
        return ans;
//        return ((ans * 2) % MOD + solve(n, l, n / 2)) % MOD;
    }
    // l on left, r on right
//    return m[{n, {l, r}}] = (solve(n, l, n / 2) + solve(n, n / 2 + 1, r)) % MOD;
    return (solve(n, l, n / 2) + solve(n, n / 2 + 1, r)) % MOD;
}*/


ll solve2(ll n, ll l, ll r) {
    if (n == 1) return 1;
//    cout << n << " " << l << " " << r << endl;

    if (l == 1 && r == n) return (((n / 2) % MOD) * ((n + 1) % MOD)) % MOD;
    // if k is <= n / 2, it will be in left half and have
    // LSB set to 0
    // now we get some value from solve, push it left by 1 and don't set the bit
    // check if both L and R lie on the same side
    // both on left
    if (2 * r <= n) {
        ll ans = solve2(n / 2, l, r);
        // each element needs to be * 2 - 1
        // * 2 direct, for -1 we need number of elems = r - l + 1
        return ((ans * 2) % MOD - (r - l + 1) + MOD) % MOD;
    }
    else if (2 * l > n) {
        ll ans = solve2(n / 2, l - n / 2, r - n / 2);
        // each element needs to be * 2
        return (ans * 2) % MOD;
    }
    // l on left, r on right
    return (solve2(n, l, n / 2) + solve2(n, n / 2 + 1, r)) % MOD;
}


int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(11);


    TESTCASES {
        ll n, l, r;
        cin >> n >> l >> r;
        cout << solve2(n, l, r) << endl;
    }
//    cout << solve(4, 2, 4);

//    for (ll n = 2; n <= (1 << 10); n *= 2) {
//        for (int i = 1; i <= n; i++) {
//            for (int j = i; j <= n; j++) {
//                ll s1 = solve(n, i, j), s2 = solve2(n, i, j);
//                if (s1 != s2) cout << n << " " << i << " " << j << " -> " << s1 << ", " << s2 << endl;
//                cout << flush;
//            }
//        }
//    }

    cout << flush;
}
