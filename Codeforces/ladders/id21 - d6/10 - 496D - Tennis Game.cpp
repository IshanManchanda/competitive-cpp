//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
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

int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(11);

//    TESTCASES {
//    }
    int n, x;
    cin >> n;
    vi cnt1(n + 1, 0), cnt2(n + 1, 0), pos1(2 * n + 3, n + 5), pos2(2 * n + 3, n + 5);
    pos1[0] = pos2[0] = 0;
    REP(i, 0, n) {
        cin >> x;
        cnt1[i + 1] = cnt1[i] + (x == 1);
        cnt2[i + 1] = cnt2[i] + (x == 2);
        if (x == 1) pos1[cnt1[i + 1]] = i + 1;
        if (x == 2) pos2[cnt2[i + 1]] = i + 1;
    }
//    cout << cnt1 << endl;
//    cout << cnt2 << endl;
//    cout << pos1 << endl;
//    cout << pos2 << endl;
//    cout << flush;
    vpi ans;
    for (int t = 1; t <= n; t++) {
        // check if this t possible
        // find position of t'th 1 or 2 from NOW.
        // from now --> Add cnt[cur]
        int flag = 1, s1 = 0, s2 = 0, cur = 0;
        while (cur < n) {
            int t1 = cnt1[cur] + t, t2 = cnt2[cur] + t;
            int p1 = pos1[t1], p2 = pos2[t2];
            if (p1 == p2 && p1 == n + 5) {
                flag = 0;
                break;
            }
            if (min(p1, p2) == n) {
                // end game
                if (p1 < p2) {
                    if (s1 < s2) {
                        flag = 0;
                        break;
                    }
                    s1++;
                    break;
                }
                else {
                    if (s2 < s1) {
                        flag = 0;
                        break;
                    }
                    s2++;
                    break;
                }
            }
            if (p1 < p2) s1++, cur = p1;
            else s2++, cur = p2;
        }
//        cout << t << " " << cur << " " << s1 << " " << s2 << " " << flag << endl;
        if (flag) ans.PB(max(s1, s2), t);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x : ans) cout << x.F << " " << x.S << "\n";


    cout << flush;
}
