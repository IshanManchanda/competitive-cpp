#pragma GCC optimize("O3,unroll-loops")
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
//#define endl "\n";

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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag,
    tree_order_statistics_node_update> indexed_set;
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

//    TESTCASES {}
    int n;
    cin >> n;
    // need idx before sorting
    vvi ranges(n);
    indexed_set closing, closing2;
    REP(i, 0, n) {
        int x, y;
        cin >> x >> y;
        ranges[i] = {x, y, (int) i};
        closing.insert({y, (int) i});
        closing2.insert({y, (int) i});
    }
    sort(all(ranges));
    int ans1[n], ans2[n];
    memset(ans1, 0, sizeof ans1);
    memset(ans2, 0, sizeof ans2);

    int i = 0;
    while (i < n) {
        // can't remove if equal starting elements still there
        // solve for all j with equal starting as i
        int j = i;
        while (j < n && ranges[j][0] == ranges[i][0]) {
            // need to check if any less or equal
            int order = closing.order_of_key({ranges[j][1] + 1, -1});
            ans1[ranges[j][2]] = order - 1;
            j++;
        }

        // remove all till j
        while (i != j) closing.erase({ranges[i][1], ranges[i][2]}), i++;
    }
    // now need to solve for ans2
    // iterate in reverse order of starting and do similar?
    // all currently in set will start before, check if any ends after
    i = n - 1;
    while (i > -1) {
        int j = i;
        while (j > -1 && ranges[j][0] == ranges[i][0]) {
            // need to check if any greater or equal
            int order = closing2.order_of_key({ranges[j][1] - 1, INT_MAX});
            ans2[ranges[j][2]] = closing2.size() - order - 1;
            j--;
        }

        while (i != j) closing2.erase({ranges[i][1], ranges[i][2]}), i--;
    }

    for (auto x : ans1) cout << x << " ";
    cout << endl;
    for (auto x : ans2) cout << x << " ";
    cout << endl;

    cout << flush;
}