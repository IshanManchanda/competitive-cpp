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
		ll m[27];
		ll vows = 0, cons = 0, max_vow = 0, max_cons = 1;
		REP(i, 0, 26)
		m[i] = 0;

		for (char c : s) {
			int x = c - 'A';
			++m[x];
			if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
				++vows;
				if (m[x] > m[max_vow]) max_vow = x;
			}
			else {
				++cons;
				if (m[x] > m[max_cons]) max_cons = x;
			}
		}

		ll ans = min(cons + 2 * (vows - m[max_vow]), vows + 2 * (cons - m[max_cons]));
		cout << "Case #" << tt << ": " << ans << "\n";
	}

	cout << flush;
}
