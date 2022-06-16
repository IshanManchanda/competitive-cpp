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
#define NEWL "\n";

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag,
//	tree_order_statistics_node_update> indexed_set;
/* find_by_order(k) and order_of_key(x) */

typedef long long ll;
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
//    memset(dp, -1, sizeof(dp));

    TESTCASES {
        int n;
        cin >> n;
        int a[n];
        REP(i, 0, n) cin >> a[i];
        map<int, vi> m;
        REP(i, 0, n) {
            m[a[i]].PB(i);
        }

        int ans = 1, cur_a = a[0], cur_l = 0, cur_r = 0;
        for (auto &can : m) {
            int this_l = can.S[0], last = can.S[0], this_r, run = 1;
            REP(i, 1, can.S.size()) {
                this_r = can.S[i];
                run -= this_r - last - 2;
                if (run <= 0) {
                    run = 1;
                    this_l = last = this_r;
                }
                else if (run > ans) {
                    ans = run;
                    cur_a = can.F;
                    cur_l = this_l;
                    cur_r = this_r;
                }
                last = this_r;
            }
        }
        cout << cur_a << " " << cur_l + 1 << " " << cur_r + 1 << NEWL;
    }

    cout << flush;
}
