//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("tune=native")

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

vvi adj, adj2;
vi a, order;
vector<bool> vis;
ll num, sum;
vi comp;

void dfs1(int v) {
    vis[v] = true;
    for (auto x : adj[v]) if (!vis[x]) dfs1(x);
    order.PB(v);
}

void dfs2(int v) {
    vis[v] = true;
    num++, sum += a[v];
    comp.PB(v);

    for (auto x : adj2[v]) if (!vis[x]) dfs2(x);
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
    // input
    int n, m;
    cin >> n >> m;
    a.assign(n, 0);
    REP(i, 0, n) cin >> a[i];
    adj.assign(n, vi()), adj2.assign(n, vi());
    REP(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[--u].PB(--v);
        adj2[v].PB(u);
    }

    // find connected components
    vis.assign(n, false);
    REP(i, 0, n) if (!vis[i]) dfs1(i);

    // for each, get sum of costs and count
    vi roots(n, 0), root_nodes;
    vl nums(n, 0), sums(n, 0);
    vvi adj_scc(n);
    vis.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order) {
        if (vis[v]) continue;
        num = 0, sum = 0, comp.clear();
        dfs2(v);
        // have the num, sum of this CC
        for (auto x : comp) roots[x] = v;
        root_nodes.PB(v);
        nums[v] = num, sums[v] = sum;
    }
    // find reduced graph (DAG)
    vector<bool> root_incl(n, false);
    for (auto x : root_nodes) root_incl[x] = true;
    REP(i, 0, n) {
        for (auto x : adj[i]) {
            if (roots[x] != roots[i]) {
                root_incl[roots[x]] = false;
//                    adj_scc[roots[i]].PB(roots[x])
            }
        }
    }
    // find all nodes with 0 incoming edges
    // all roots with root_incl marked true

    ll mod = 998244353;
    ll ans = 0;
    REP(i, 0, n) {
        if (!root_incl[i]) continue;
        ll temp = (sums[i] * mod_inv(nums[i], mod)) % mod;
        ans = (ans + temp) % mod;
    }
    cout << ans;
//    }

    cout << flush;
}
