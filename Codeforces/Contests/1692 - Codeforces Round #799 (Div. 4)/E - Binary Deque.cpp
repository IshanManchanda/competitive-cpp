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
        int n, s;
        cin >> n >> s;
        int a[n];
        REP(i, 0, n) cin >> a[i];
        int cs = accumulate(a, a + n, 0);
        if (cs <= s) {
            cout << ((cs < s) ? "-1\n" : "0\n");
            continue;
        }
        int cur_rem = 0, cur_cost = 0, diff = cs - s;
        map<int, int> cost;  // Just use array!
        cost[0] = 0;
        REP(i, 0, n) {
            if (a[i] == 0) cur_cost++;
            else {
                cur_rem++;
                cur_cost++;
                cost[cur_rem] = cur_cost;
            }
        }

        int ans = cost[diff];
        cur_rem = cur_cost = 0;
        RREP(i, n - 1, -1) {
            if (a[i] == 0) cur_cost++;
            else {
                cur_rem++;
                cur_cost++;
                ans = min(ans, cur_cost + cost[diff - cur_rem]);
            }
        }
        cout << ans << NEWL;
    }

    cout << flush;
}
