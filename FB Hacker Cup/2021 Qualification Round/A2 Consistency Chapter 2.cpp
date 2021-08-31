#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (ll i = (a); i < (b); ++i)
#define RREP(i,a,b) for (ll i = (a); i > (b); --i)

#define NEG_INF (-LLONG_MAX)

typedef long long ll;
//typedef __int128_t lll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	REP(tt, 1, t + 1) {
		string s;
		cin >> s;
		ll m[26], adj[26][26], k;

		REP(i, 0, 26) m[i] = 0;
		for (char c : s) ++m[c - 'A'];
		REP(i, 0, 26) REP(j, 0, 26) adj[i][j] = INT_MAX;
		REP(i, 0, 26) adj[i][i] = 0;

		cin >> k;
		REP(i, 0, k) {
			cin >> s;
			adj[s[0] - 'A'][s[1] - 'A'] = 1;
		}

		REP(kk, 0, 26)
			REP(ii, 0, 26)
				REP(jj, 0, 26)
					if (adj[ii][jj] > (adj[ii][kk] + adj[kk][jj]))
						adj[ii][jj] = adj[ii][kk] + adj[kk][jj];

		ll dist, min_dist = INT_MAX;
		REP(i, 0, 26) {
			dist = 0;
			REP(j, 0, 26) {
				if (m[j] != 0 && adj[j][i] == INT_MAX) {
					dist = INT_MAX;
					break;
				}
				dist += m[j] * adj[j][i];
			}
			if (dist < min_dist) {
				min_dist = dist;
			}
		}

		ll ans = -1;
		if (min_dist != INT_MAX) ans = min_dist;
		cout << "Case #" << tt << ": " << ans << "\n";
	}

	cout << flush;
}
