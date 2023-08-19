//#pragma GCC optimize("O2,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#pragma GCC target("avx,avx2,fma")

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
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(19);

//    TESTCASES {}
    int n, m;
    cin >> n >> m;
    vi a(m, 0);
    REP(i, 0, n) {
        int x, y;
        cin >> x;
        REP(j, 0, x) {
            cin >> y;
            a[y - 1] |= 1;
        }
    }
    cout << (accumulate(a.begin(), a.end(), 0) == m ? "YES" : "NO");

    cout << flush;
}
