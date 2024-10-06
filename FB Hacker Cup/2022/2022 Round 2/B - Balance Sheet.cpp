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

#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
#define RREP(i, a, b) for (auto i = (a); i > (b); --i)

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
	FILE_IN
	FILE_OUT
//	cout << setprecision(19);

    TESTCASES1 {
        int n, k;
        cin >> n >> k;
        ll buyd[n], selld[n], buy[n], sell[n];
        REP(i, 0, n) cin >> buyd[i] >> selld[i] >> buy[i] >> sell[i];
        map<ll, vl> buy1, sell1;
        REP(i, 0, n) {
            buy1[buyd[i]].PB(i);
            sell1[selld[i]].PB(i);
        }

//        for (auto xa : a1) cout << xa << " ";
//        cout << endl;
//        for (auto xa : b1) cout << xa << " ";
//        cout << endl;

        ll ans = 0;
        priority_queue<ll> ansq;
        vvl dp(n, vl(1, 0));
        // iterate backwards on sell days
        for (auto x = sell1.rbegin(); x != sell1.rend(); x++) {
            // get all sellers on that day (to assign)
            vl sellers((*x).second);
            // get all buyers on that day (to pull values from)
            vl buyers(buy1[(*x).first]);
            // sort buyers and sellers on that day on their buy and sell vals
            sort(sellers.begin(), sellers.end(), [&] (ll a, ll b) {
                return sell[a] < sell[b];
            });
            sort(buyers.begin(), buyers.end(), [&] (ll a, ll b) {
                return buy[a] < buy[b];
            });
            // need to ensure that buy val > sell val for each pair
            // need to essentially 2 pointers on them. Sell is the primary and
            // Buy is the secondary. Move Buy until <= sell. Then move Sell down.
            int buyp = buyers.size() - 1, sellp = sellers.size() - 1;
            priority_queue<ll> q;
//            cout << *x << endl;
            while (sellp >= 0) {
                while (buyp >= 0 && buy[buyers[buyp]] > sell[sellers[sellp]]) {
                    // iterate over this buyer and add
                    for (auto y: dp[buyers[buyp]]) {
                        q.push(-y - buy[buyers[buyp]]);
                        while (q.size() > k) q.pop();
                    }
                    buyp--;
                }

                priority_queue<ll> q1;
                while (!q.empty()) {
                    ll t = q.top();
                    q.pop();
                    if (t != 0) {
                        dp[sellers[sellp]].push_back(-t - sell[sellers[sellp]]);
                        q1.push(t);
                        ansq.push(t + sell[sellers[sellp]]);
                        while (ansq.size() > k) ansq.pop();
                    }
                }
                q = q1;
                sellp--;
            }
        }
//        cout << dp << endl;
        while (!ansq.empty()) {
            ans = (ans - ansq.top()) % MOD;
            ansq.pop();
        }
        CASEOUT << (ans + MOD) % MOD << endl;
    }
    cout << flush;
}
