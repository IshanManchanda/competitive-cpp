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
#define MOD (1'000'000'007ll)
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


int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(11);


//    TESTCASES {
//    }
    int n;
    cin >> n;
    pair<ll, pi> bits[n];
    REP(i, 0, n) cin >> bits[i].ff;
    REP(i, 0, n) cin >> bits[i].ss.ff;
    REP(i, 0, n) cin >> bits[i].ss.ss;
    sort(bits, bits + n, greater<>());
    // compute suffix sums of original and final costs of set bits
    ll suf_ori[n + 1], suf_fin[n + 1];
    suf_fin[n] = suf_ori[n] = 0;
    RREP(i, n - 1, -1) {
        suf_ori[i] = suf_ori[i + 1] + bits[i].ss.ff * bits[i].ff;
        suf_fin[i] = suf_fin[i + 1] + bits[i].ss.ss * bits[i].ff;
    }

    // dp1: cost of solving first i bits using j EXTRA moves
    // dp2: total c value set after processing first i bits and j moves
    ll dp1[n + 1][n + 1], dp2[n + 1][n + 1];
    REP(i, 0, n + 1) REP(j, 0, n + 1) dp1[i][j] = dp2[i][j] = INT_MAX;
    dp1[0][0] = dp2[0][0] = 0;
//    ll ans = 0;
    REP(i, 0, n) {
        // if this is unset and doesn't need to be set in the ans
        if (bits[i].ss.ff == 0 && bits[i].ss.ss == 0) {
            // all costs and prefix values remain same
            REP(j, 0, n + 1) {
                dp1[i + 1][j] = dp1[i][j];
                dp2[i + 1][j] = dp2[i][j];
            }
            continue;
        }

        // if this is set and we need to unset it, simply unset
        if (bits[i].ss.ff == 1 && bits[i].ss.ss == 0) {
            // cost of unsetting: total cost set in prefix (dp2)
            // and total cost of suffix originally
            // and dp2 continues to be same
            REP(j, 0, n + 1) {
                dp1[i + 1][j] = dp1[i][j] + dp2[i][j] + suf_ori[i + 1];
                dp2[i + 1][j] = dp2[i][j];
            }
            continue;
        }

        // if this is unset and we need to set it, we'll set it at the end
        if (bits[i].ss.ff == 0 && bits[i].ss.ss == 1) {
            // we pay the cost for it then: prefix stays in same state
            // and suffix is in final state
            // dp2 also stays same
            REP(j, 0, n + 1) {
                dp1[i + 1][j] = dp1[i][j] + dp2[i][j] + suf_fin[i + 1];
                dp2[i + 1][j] = dp2[i][j];
            }
            continue;
        }

        REP(j, 0, n) {
            // we try to set the i'th bit in j moves
            // now, this bit is set and we choose whether to unset and later set

            // HAVE TO PICK AND SET ONLY ONE??
            // if we don't unset, then no extra moves used
            dp1[i + 1][j] = dp1[i][j];
            dp2[i + 1][j] = dp2[i][j];

            // we set this bit
        }
    }


    cout << flush;
}
