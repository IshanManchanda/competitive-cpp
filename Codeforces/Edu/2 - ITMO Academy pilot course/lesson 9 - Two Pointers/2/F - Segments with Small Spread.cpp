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

#define TIME_START using std::chrono::high_resolution_clock; using std::chrono::duration_cast; using std::chrono::duration; using std::chrono::milliseconds; auto ttt1 = high_resolution_clock::now();
#define TIME_STOP auto ttt2 = high_resolution_clock::now(); duration<double, std::milli> ms_double = ttt2 - ttt1; cerr << ms_double.count() << "ms\n";

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
// v.insert(v.mutable_begin() + idx, v2)
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
typedef tuple<ll, ll, ll> tl;
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
//    TIME_START
    FAST_IO
//    FILE_IN
//    FILE_OUT
    cout << setprecision(19);

    // ll mod = 998'244'353;
    // TESTCASES {}

    ll n, k;
    cin >> n >> k;
    vl a(n);
    cinai(a, n);

    // Instead of monotonic dequeue, one approach is to use 2 stacks
    // for the deque. And to store both min and max we use 3 stacks
    // (one for elements, one for running mins and running maxs).
    // Total of 6 stacks.
    // When we pop from s2 into s1 (done when we want to remove i'th element),
    // we recompute the running mins and maxs in reverse order (stack insertion
    // order) which allows easy removal using the same logic as easy addition.
    deque<ll> mins, maxs;
    // For maintain monotonic min and max queues.
    // Add element if equal also.
    // Push j, while not good push i. Then add j - i + 1.
    ll ans = 0, i = 0;
    for (ll j = 0; j < n; j++) {
        while (!mins.empty() && mins.back() > a[j]) mins.pop_back();
        mins.push_back(a[j]);

        while (!maxs.empty() && maxs.back() < a[j]) maxs.pop_back();
        maxs.push_back(a[j]);

        while (maxs.front() - mins.front() > k) {
            if (maxs.front() == a[i]) maxs.pop_front();
            if (mins.front() == a[i]) mins.pop_front();
            i++;
        }
        // i..j segment is good.
        ans += j - i + 1;
    }
    cout << ans << endl;

    cout << flush;
//    TIME_STOP
}
