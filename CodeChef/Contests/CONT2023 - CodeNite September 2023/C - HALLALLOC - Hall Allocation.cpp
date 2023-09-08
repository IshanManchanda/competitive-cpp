//#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")
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


bool check(int val, vi &a, vpi &e, int k) {
    vi adj[a.size()];
    for (auto ee : e) {
        if (a[ee.F - 1] < val || a[ee.S - 1] < val) continue;
        adj[ee.F - 1].PB(ee.S - 1);
        adj[ee.S - 1].PB(ee.F - 1);
    }
    // check if there are any connected components with more than k nodes.
    vector<bool> vis(a.size(), false);
    REP(i, 0, a.size()) {
        if (a[i] < val || vis[i]) continue;
        // otherwise bfs and return true if more than k
        queue<int> q;
        vis[i] = true;
        q.push(i);
        int cnt = 1;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto x : adj[t]) {
                if (vis[x]) continue;
                vis[x] = true;
                q.push(x);
                cnt++;
            }
        }
        if (cnt >= k) return true;
    }
    return false;
}


int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(11);


    // OLD approach
    // binary search on ans?
    // drop nodes one-by-one in order of their cgpa
    // check if there are more than k connected nodes
    // they must be connected within themselves!
    // cutpoint won't work
    // if we binary search on this, then 30 * x
    // if that can be done in linear time then sorted

    // NEW APPROACH
    // binary search on cgpa
    // drop all nodes with cgpa below thresh
    // now, need to check if we can form a group of k such that k nodes
    // are connected among themselves only
    // if you have a connected group of k nodes, always true?
    // just bfs and check number of nodes in each component?
    // extra lg n terms when forming the graph
    // will need to check in 2 sets if this node part or not
    // nlgn * 30
    // 1e8, v tight
    // instead of bin search over whole range, bin search on
    // sorted version of cgps?
    // 17.6 factor instead of 30, should be good
    // n lgn lg n

    TESTCASES {
        int n, m, k;
        cin >> n >> m >> k;
        vi a(n);
        int b[n + 2];
        REP(i, 0, n) cin >> a[i];
        vpi e(m);
        REP(i, 0, m) cin >> e[i].F >> e[i].S;

        REP(i, 0, n) b[i + 1] = a[i];
        // sentinel values
        b[0] = -1, b[n + 1] = 1000000007;
        sort(b, b + n + 2);
        // lo: can always drop values less than eq b[i] and form group
        // hi: can never  drop values less than eq b[i] and form group
        int lo = 0, hi = n + 1;
        while (hi > lo + 1) {
            int mid = (lo + hi) / 2;
            if (check(b[mid], a, e, k)) lo = mid;
            else hi = mid;
        }
        cout << b[lo] << "\n";
    }

    cout << flush;
}
