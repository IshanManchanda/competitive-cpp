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
#define CASEOUT cout << "Case #" << ttt << ": "

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
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag,
//	tree_order_statistics_node_update> indexed_set;
/* find_by_order(k) and order_of_key(x) */

//#include <ext/rope>
//using namespace __gnu_cxx;
//rope<int> v1;  // can use as usual STL container
// v1.push_back(x), v1.erase(start, len)
// v2 = v1.substr(l, r - l + 1)
// v.insert(v.mutable_begin(), v2)
// auto it = v.mutable_begin(); it != v.mutable_end(); it++
// can index using [ ] to return const ref
// modify: v.mutable_reference_at(i) = x

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//gp_hash_table<int, int> table;
// can use any other type as key if defined a hash function
//struct chash {
//    int operator()(pi x) const { return x.first * 31 + x.second; }
//};
//gp_hash_table<pi, int, chash> table;


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

const int MAXN = 1000007, mod = 1000000007;
int n;
pair<pi, pi> t[4*MAXN];  // store min and max
int lazy[4*MAXN];  // lazy prop

void build(vi &a, int v, int tl, int tr) {
    if (tl == tr) {
        // min, max
        t[v] = {{tl, tl}, {a[tl], a[tl]}};
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);

        int min_pos, min_val, max_pos, max_val;
        if (t[v*2].ss.ff <= t[v*2+1].ss.ff) min_pos = t[v*2].ff.ff, min_val = t[v*2].ss.ff;
        else min_pos = t[v*2+1].ff.ff, min_val = t[v*2+1].ss.ff;
        if (t[v*2].ss.ss >= t[v*2+1].ss.ss) max_pos = t[v*2].ff.ss, max_val = t[v*2].ss.ff;
        else max_pos = t[v*2+1].ff.ss, max_val = t[v*2+1].ss.ff;

        t[v] = {{min_pos, max_pos}, {min_val, max_val}};
    }
}

void push(int v) {
    // Subtract from mod, swap min and max
    if (!lazy[v]) return;
    t[v*2] = {mod - t[v*2].ss, mod - t[v*2].ff};
    lazy[v*2] ^= lazy[v];
    t[v*2+1] = {mod - t[v*2+1].ss, mod - t[v*2+1].ff};
    lazy[v*2+1] ^= lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] = {mod - t[v].ss, mod - t[v].ff};
        lazy[v] ^= 1;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm));
        update(v*2+1, tm+1, tr, max(l, tm+1), r);
        t[v] = {min(t[v*2].ff, t[v*2+1].ff), max(t[v*2].ss, t[v*2+1].ss)};
    }
}

int query(int v, int tl, int tr, int l, int r) {
    // TODO: figure this out
    if (l > r)
        return INT_MIN;

    if (l == tl && tr == r)
        return max(t[v].ff, t[v].ss);
    push(v);
    int tm = (tl + tr) / 2;
    // mod -
    auto q1 = query(v*2, tl, tm, l, min(r, tm));
    auto q2 = query(v*2+1, tm+1, tr, max(l, tm+1), r);
    return max(q1, q2);
}


int main() {
    FAST_IO
    FILE_IN
    FILE_OUT
//    cout << setprecision(11);

    TESTCASES1 {
        cin >> n;
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
        vi a(n, 0);
        cinai(a, n);
        build(a, 1, 0, n - 1);
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            update(1, 0, n - 1, l, r);
            int ans = query(1, 0, n - 1, 0, n - 1);
        }
    }

    cout << flush;
}
