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
#define cinai(a, n) REP(i, 0, n) cin >> a[i]
#define cinan(a, n) int n; cin >> n; int a[n]; cinai(a, n)
#define cinanl(a, n) ll n; cin >> n; ll a[n]; cinai(a, n)

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

bool check_haha(string &s, int i) {
    return s.substr(i, 4) == "haha";
}

class var {
public:
    ll len, num;
    string start, end;

    var(): len(0), num(0) {};
    var(string &s) {
        len = s.size();
        num = 0;
        if (len >= 4) num += (s.substr(0, 4) == "haha");
        if (len >= 5) num += (s.substr(1, 4) == "haha");
        start = s.substr(0, min(3, (int) s.size()));
        end = s.substr(s.size() - min(3, (int) s.size()), min(3, (int) s.size()));
    };
};

var merge(var &v1, var &v2) {
    var v3;
    string temp;
    temp = v1.start + v2.start;
    v3.start = temp.substr(0, min(3, (int) temp.size()));
    temp = v1.end + v2.end;
    v3.end = temp.substr(temp.size() - min(3, (int)temp.size()), min(3, (int)temp.size()));
    v3.len = v1.len + v2.len;
    v3.num = v1.num + v2.num;
    temp = v1.end + v2.start;
    if (temp.size() >= 4) {
        if (temp.size() >= 4) v3.num += (temp.substr(0, 4) == "haha");
        if (temp.size() >= 5) v3.num += (temp.substr(1, 4) == "haha");
        if (temp.size() >= 6) v3.num += (temp.substr(2, 4) == "haha");
    }
    return v3;
}


int main() {
    FAST_IO
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(11);

    TESTCASES {
        int n;
        cin >> n;
        map<string, var> m;
        ll ans;
        while (n--) {
            // either 3 or 5 strings.
            string s1, s2, s3;
            cin >> s1 >> s2 >> s3;
            if (s2 == "=") {
                string s4, s5;
                cin >> s4 >> s5;
                // c = a + b. s1, s3, s5
                m[s1] = merge(m[s3], m[s5]);
//                cout << m[s1].len << " " << m[s1].num << " " << m[s1].start << " " << m[s1].end << endl;
            }
            else {
                // c := str. s1, s3
                m[s1] = var(s3);
//                cout << m[s1].len << " " << m[s1].num << " " << m[s1].start << " " << m[s1].end << endl;
            }
            if (n == 0) ans = m[s1].num;
        }
        cout << ans << endl;
    }

    cout << flush;
}
