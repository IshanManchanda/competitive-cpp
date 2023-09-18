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

// dp1 -> the max number of elements for n coins
// dp2 -> the min val we take in the process
map<ll, ll> dp1, dp2;

pl solve(ll k, vl &c) {
    if (dp1.find(k) != dp1.end()) return {dp1[k], dp2[k]};
    if (k < 0) {
        return {-INT_MAX, -INT_MAX};
    }
    if (k == 0) {
        dp1[k] = 0, dp2[k] = INT_MAX;
        return {0, INT_MAX};
    }
    if (k < c[0]) {
        dp1[k] = 0, dp2[k] = 0;
        return {0, INT_MAX};
    }
    // in order, try taking each and see what first val we get
    // as long as first val stays
    // need to maximize the min val we take in the process
    // for each option, this is min of current taken and the ret val
    ll max_taken = -1, best_min = -1;
    for (int i = 0; i < (int)c.size(); i++) {
        if (max_taken == -1) {
            // run this and just set vals
            auto [x, y] = solve(k - c[i], c);
            max_taken = x + 1, best_min = c[i];
            continue;
        }
        if (k < c[i]) break;
        auto [x, y] = solve(k - c[i], c);
        x++;
        if (x < max_taken) break;
        y = min(y, c[i]);
        max_taken = x, best_min = max(best_min, y);
    }
    dp1[k] = max_taken, dp2[k] = best_min;
    return {dp1[k], dp2[k]};
}

int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(11);


    TESTCASES {
        ll n, k;
        cin >> n;
        ll c[n];
        cinai(c, n);
        cin >> k;
        deque<pl> q;
        REP(i, 0, n) {
            while (!q.empty() && q.back().ff >= c[i]) q.pop_back();
            if (q.empty() || 2 * q.front().ff > c[i]) q.PB(c[i], i);
        }

        // all elements are < 2min1
        // how many times is it guaranteed we should take min1?
        // let's consider k = min1 * min2 + alpha. If we take only min1, we can
        // take min2. If we take even 1 min2, we can take at most min2 - 1
        // thus we always reduce k to less than min1 * min2.
        // simply k1 = k % (min1 * min2), while inc1 = (k / (min1 * min2)) * min2
//        for (auto x1 : q) cout << x1 << endl;
        auto [min1, p1] = q.front();
//        cout << min1 << " " << p1 << "\n" << flush;
        q.pop_front();
        ll min2, p2;
        if (!q.empty()) {
            auto [x, y] = q.front();
            min2 = x, p2 = y;
        }
        else {
            ll inc1 = k / min1;
            REP(i, 0, p1 + 1) cout << inc1 << " ";
            REP(i, p1 + 1, n) cout << "0 ";
            cout << "\n";
            continue;
        }
        ll inc1 = (k / (min1 * min2)) * min2, k1 = k - inc1 / min2;
        //
        map<ll, ll> pos;
        vl coins;
        pos[min1] = p1, coins.PB(min1);
        for (auto [val, p] : q)
            pos[val] = p, coins.PB(val);
        solve(k1, coins);
//        for (auto x1 : dp1) cout << x1 << " ";
//        cout << endl;
//        for (auto x1 : dp2) cout << x1 << " ";
//        cout << endl;
        ll y = dp2[k1];
//        cout << y << endl;
        vl diff(n + 1, 0);
        diff[0] = inc1, diff[p1 + 1] = -inc1;
        while (k1 >= coins[0]) {
            diff[0]++;
            diff[pos[y] + 1]--;
            k1 -= y;
            y = dp2[k1];
        }
        // compute firstly needs to maximize the number of
        // elements taken
        // and secondly needs to maximize the value of the first element
        // taken
        // solve will return n_taken, first_taken
        // and then we go to k1 - first_taken for the next element
        // and so on
        // can use diff array to get the sum
        ll ans = 0;
        REP(i, 0, n) {
            ans += diff[i];
            cout << ans << " ";
        }
        cout << "\n";
    }

    cout << flush;
}
