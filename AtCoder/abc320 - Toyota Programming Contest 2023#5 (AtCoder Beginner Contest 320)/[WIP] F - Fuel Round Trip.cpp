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


int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(11);


//    TESTCASES {
//    }
    ll n, h;
    cin >> n >> h;
    ll a[n + 1];
    a[0] = 0;
    REP(i, 1, n + 1) cin >> a[i];
    ll p[n], f[n];
    REP(i, 1, n) cin >> p[i] >> f[i];
    ll dp[n + 1][h + 1][h + 1];
    REP(i, 0, n + 1) REP(j, 0, h + 1) REP(k, 0, h + 1) dp[i][j][k] = LLONG_MAX;

    // we start with h fuel and can return with any amount
    REP(k, 0, h + 1) dp[0][h][k] = 0;
    REP(i, 1, n + 1) {
        REP(j, 0, h + 1) {
            REP(k, 0, h + 1) {
                if (i == n && j != k) continue;
//                cout << i << " " << j << " " << k << "\n" << flush;
                ll d = a[i] - a[i - 1];  // dist from prev
                // consider the 3 cases:
                // 1, we don't use any fuel
                // we need to have j + d in the prev, and we will have
                // k - d in return
                if (j + d <= h && k >= d)
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + d][k - d]);
                if (i == n) continue;
                // 2, we use fuel in the forward journey
                // we can reach with any fuel >= d, and we end up with
                // min(fuel + F, H)
                // so if j (fuel rn) is < H, we must have had j - F previously
                // if j == h, we need to iterate over all values of fuel
                // such that f + F >= H, impl f >= H - F
                // and also f >= d
                // so f := min(d, h - F) -> H
                if (j < h && j - f[i] + d <= h && j - f[i] >= d && k >= d && dp[i - 1][j - f[i] + d][k - d] != LLONG_MAX)
                    dp[i][j][k] = min(dp[i][j][k], p[i] + dp[i - 1][j - f[i] + d][k - d]);
                if (j == h && k >= d) {
                    REP(f1, max(d, h - f[i] + d), h + 1)
                        if (dp[i - 1][f1][k - d] != LLONG_MAX)
                            dp[i][j][k] = min(dp[i][j][k], p[i] + dp[i - 1][f1][k - d]);
                }
                // 3, we use fuel in the backward journey
                // we arrived here with k, top up to min(h, k + f)
                // and then cover the distance to prev
                if (j + d <= h && min(h, k + f[i]) >= d && dp[i - 1][j + d][min(h, k + f[i]) - d] != LLONG_MAX)
                    dp[i][j][k] = min(dp[i][j][k], p[i] + dp[i - 1][j + d][min(h, k + f[i]) - d]);
            }
        }
    }
//    REP(i, 0, n + 1) {
//        cout << i << "\n";
//        REP(j, 0, h + 1) {
//            cout << j << ": ";
//            REP(k, 0, h + 1) cout << dp[i][j][k] << " ";
//            cout << "\n";
//        }
//        cout << "\n";
//    }
    ll ans = LLONG_MAX;
    REP(j, 0, h + 1) ans = min(ans, dp[n][j][j]);
    if (ans == LLONG_MAX) ans = -1;
    cout << ans;

    cout << flush;
}
