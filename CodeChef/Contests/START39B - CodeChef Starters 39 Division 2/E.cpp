//#pragma GCC optimize("O3,unroll-loops")
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
//typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vi> vvl;

int dfs(int u, int v, vector<pair<int, int>> adj[]) {
    int x = 1;
    for (auto& w : adj[u]) {
        if (w.F == v) continue;
        x += dfs(w.F, u, adj);
    }
    return x;
}

int main() {
    FAST_IO
    // TODO: get a prime/prime factor precompute tool.
//	FILE_IN
//	FILE_OUT
//	cout << setprecision(19);

    TESTCASES {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vi islands[26];
        REP(j, 0, 26) {
            char c = 'a' + j;
            int rl = 0;
            REP(i, 0, n) {
                if (s[i] == c) rl++;
                else {
                    islands[j].PB(rl);
                    rl = 0;
                }
            }
            islands[j].PB(rl);
            sort(all(islands[j]), greater<>());
            while (islands[j].size() <= n) islands[j].PB(0);
        }
        vi partials(26, 0);
        REP(i, 0, n + 1) {
            REP(j, 0, 26) {
                partials[j] += islands[j][i];
            }
            cout << *max_element(all(partials)) << " ";
        }
        cout << NEWL;
    }

    cout << flush;
}
