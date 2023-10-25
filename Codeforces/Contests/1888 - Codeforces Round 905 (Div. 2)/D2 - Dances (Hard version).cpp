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

ll get_ans(vi &a, vi &b, int n, int k, int k_prev) {
    if (k_prev == -1) a[n - 1] = k;
    else {
        // find k_prev and set it as k
        auto pos = lower_bound(all(a), k_prev);
        *pos = k;
    }
    sort(all(a));

//        for (auto x : a) cout << x << " ";
//        cout << endl;
//        for (auto x : b) cout << x << " ";
//        cout << endl;

    // lo never possible, hi always
    ll lo = -1, hi = n;
    while (hi > lo + 1) {
        ll mid = (lo + hi) / 2;
        int flag = 1;
//            cout << mid << ": ";
        REP(i, mid, n) {
//                cout << b[i] << "," << a[n - i - 1] << ", ";
            if (b[i] <= a[i - mid]) {
                flag = 0;
                break;
            }
        }
//            cout << flag << endl;
        if (flag) hi = mid;
        else lo = mid;
    }
    return hi;
}

int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(11);


    TESTCASES {
        int n, m;
        cin >> n >> m;
        vi a(n, 0), b(n, 0);
        cinai(a, n - 1);
        cinai(b, n);
        sort(all(b));
        ll a1 = get_ans(a, b, n, 1, -1);
        // lo never changes ans, hi always does
        ll lo = 1, hi = m + 1, k_prev = 1;
        while (hi > lo + 1) {
            ll mid = (lo + hi) / 2;
            ll a2 = get_ans(a, b, n, mid, k_prev);
//            cout << mid << " -> " << a2 << endl;
            if (a2 == a1) lo = mid;
            else hi = mid;
            k_prev = mid;
        }
//        cout << a1 << " " << hi << endl;
        cout << m * a1 + m - hi + 1 << endl;
//        cout << endl;
    }


    cout << flush;
}
