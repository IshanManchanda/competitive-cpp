//#pragma GCC optimize("O2,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
//#pragma GCC target("avx,avx2,fma")

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
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

bool check(ll len, vvl &rmq, vvl &gcd, ll n, ll a[]) {
    // check if in all windows of size len, is rmq == gcd
    REP(i, 0, n - len + 1) {
        ll k = log2(len);
//        if (i == 0) cout << "k: " << k << " ";
        ll r = rmq[i + len - (1 << k)][k];
        if (a[rmq[i][k]] < a[r]) r = rmq[i][k];
        r = a[r];
        ll g = __gcd(gcd[i][k], gcd[i + len - (1 << k)][k]);
//        if (i == 1 && len == 4) cout << "I1 L4: " << r << " " << g << endl;
        if (r == g) return true;
    }
    return false;
}


int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
    cout << setprecision(11);

//    TESTCASES {
//
//    }

    ll n;
    cin >> n;
    ll a[n];
    REP(i, 0, n) cin >> a[i];

    vvl rmq(n, vl(19)), gcd(n, vl(19));
    REP(i, 0, n) rmq[i][0] = i, gcd[i][0] = a[i];
    REP(j, 1, 19) {
        if ((1 << j) > n) break;
        REP(i, 0, n) {
            // (1 << j) is the new length
            if (a[rmq[i][j - 1]] < a[rmq[min(n - 1, i + (1 << (j - 1)))][j - 1]])
                rmq[i][j] = rmq[i][j - 1];
            else rmq[i][j] = rmq[min(n - 1, i + (1 << (j - 1)))][j - 1];
            gcd[i][j] = __gcd(gcd[i][j - 1], gcd[min(n - 1, i + (1 << (j - 1)))][j - 1]);
        }
    }

//    REP(j, 0, 19) {
//        if ((1 << j) > n) break;
//        REP(i, 0, n) {
//            cout << rmq[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    REP(j, 0, 19) {
//        if ((1 << j) > n) break;
//        REP(i, 0, n) {
//            cout << gcd[i][j] << " ";
//        }
//        cout << endl;
//    }

    // find max len
    ll lo = 0, hi = n + 1; // lo always possible, hi never possible
    while (hi > lo + 1) {
        ll mid = (lo + hi) / 2;
//        cout << lo << ", " << hi << " -> " << mid << ": ";
        if (check(mid, rmq, gcd, n, a)) lo = mid;
        else hi = mid;
//        cout << (check(mid, rmq, gcd, n, a)) << endl;
    }
    // lo is the largest possible. get all windows of length lo that sat.
//    cout << lo << endl;

    vl b;
    REP(i, 0, n - lo + 1) {
        ll k = lo == 0 ? 0 : log2(lo);
//        if (i == 0) cout << k << endl;
        ll r = rmq[i + lo - (1 << k)][k];
        if (a[rmq[i][k]] < a[r]) r = rmq[i][k];
        r = a[r];
        ll g = __gcd(gcd[i][k], gcd[i + lo - (1 << k)][k]);
//        if (i == 0) cout << i << " rmq: " << r << " gcd: " << g << endl;
        if (r == g) b.PB(i + 1);
    }
    cout << b.size() << " " << lo - 1 << endl;
    for (auto x : b) cout << x << " ";

    cout << flush;
}
