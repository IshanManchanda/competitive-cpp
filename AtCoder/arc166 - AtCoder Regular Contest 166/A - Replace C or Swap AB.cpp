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


int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(11);

    TESTCASES {
        int n;
        string x, y;
        cin >> n >> x >> y;
        int xa = 0, xb = 0, xc = 0, ya = 0, yb = 0, flag = 1, s = 0;

        for (int i = 0; i <= n; i++) {
            if (i == n || y[i] == 'C') {
                if (i != n && x[i] != 'C') {
                    flag = 0;
                    break;
                }
                // segment break, process the previous one
                // if size only 1, all ok
                if (s >= i - 1) {
                    s = i + 1;
                    // check the previous 1 or 0 partition
                    if (xa > ya || xb > yb) {
                        flag = 0;
                        break;
                    }
                    xa = xb = xc = ya = yb = 0;
                    continue;
                }
                else {
                    // maintain how many initial Cs become As
                    int ca = ya - xa;
                    xa = xb = xc = ya = yb = 0;
                    // note that i not incl in the segment
                    for (int j = s; j < i; j++) {
                        if (x[j] == 'A') xa++;
                        else if (x[j] == 'B') xb++;
                        else if (ca) xa++, ca--;
                        else xb++;

                        if (y[j] == 'A') ya++;
                        else if (y[j] == 'B') yb++;

                        if (xa < ya) {
                            flag = 0;
                            break;
                        }
                    }
                    if (xa != ya || xb != yb) {
                        flag = 0;
                        break;
                    }
                    s = i + 1;
                    xa = xb = xc = ya = yb = 0;
                }
            } else {
                if (x[i] == 'A') xa++;
                else if (x[i] == 'B') xb++;
                else xc++;
                if (y[i] == 'A') ya++;
                else if (y[i] == 'B') yb++;

                // also need yb - xb c's to become b
                // currently counted c might need to become a b though
                // for each segment, we should convert the leftmost Cs
                // to As and the rest to Bs as per the requirements
                if (xa + xc < ya) {
                    flag = 0;
                    break;
                }
            }

        }
        if (xa > ya || xb > yb) flag = 0;
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    cout << flush;
}
