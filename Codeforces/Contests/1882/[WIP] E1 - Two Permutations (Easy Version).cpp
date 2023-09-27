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
#define cinai(a, n) REP(ii, 0, n) cin >> a[ii]
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

int check_pos(vi &a, int x) {
    // check if a is sorted, return a neg number then
    // else returns a pos number which is the position of x
    int flag = 0, px = 0;
    REP(i, 0, (int)a.size()) {
        if (a[i] == x) px = i;
        if (a[i] != i + 1) flag = 1;
    }
    // all sorted
    if (!flag) return -1;
    return px;
}

vi steps(vi &a) {
    // check as well as find position of the element we care about
    int cur = 2, px, p1, n = a.size();
    vi s;
    vi b;
    // start with cur = 2, find pos of 1 before every cycle and
    // move it to the end?
    while ((p1 = check_pos(a, cur - 1)) != -1) {
        b.clear();
        if (p1 != n - 1) {
            if (a[p1 + 1] == cur) {
                cur++;
                continue;
            }
            s.PB(p1 + 1); // operate p1 + 1
            // copy over to b
            REP(j, p1 + 2, n) b.PB(a[j]);
            b.PB(a[p1 + 1]);
            REP(j, 0, p1 + 1) b.PB(a[j]);
            swap(a, b);
            b.clear();
        }
        px = check_pos(a, cur);
        if (px == -1) return s;
        s.PB(px);  // operate px
        REP(j, px + 1, n) b.PB(a[j]);
        b.PB(a[px]);
        REP(j, 0, px) b.PB(a[j]);
        swap(a, b);
        cur++;
    }
    return s;
}


int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(11);


//    TESTCASES {
//    }

    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    cinai(a, n);
    cinai(b, m);
    // get seq for a
    vi xa{a}, xb{b};
    vi sa = steps(xa), sb = steps(xb);
//    cout << sa << endl;
//    cout << sb << endl;

    int d = (int)sa.size() - (int)sb.size();
    if (d == 0) {
        REP(i, 0, (int) sa.size()) cout << sa[i] + 1 << " " << sb[i] + 1 << endl;
        cout << flush;
        return 0;
    }
    if (abs(d) % 2 == 0) {
        if (d > 0) {
            while (sa.size() != sb.size()) {
                sb.PB(1);
                sb.PB(n);
            }
        }
        else {
            while (sa.size() != sb.size()) {
                sa.PB(1);
                sa.PB(m);
            }
        }
        REP(i, 0, (int) sa.size()) cout << sa[i] + 1 << " " << sb[i] + 1 << endl;
        cout << flush;
        return 0;
    }
    else {
        if (n == 2 && m == 2) {
            cout << -1 << flush;
            return 0;
        }
        if (d > 0) {
            if (m % 2) REP(i, 0, m) sb.PB();
            else REP(i, 0, m) sb.PB();
            while (sa.size() != sb.size()) {
                sb.PB(1);
                sb.PB(n);
            }

        }
        else {

        }
    }
    // if lengths equal, can cout
    // if diff is even, pad the shorter one


    cout << flush;
}
