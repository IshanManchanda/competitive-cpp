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
		int n;
		char x;
		cin >> n;
		int a[n][n];
		REP(i, 0, n) {
			REP(j, 0, n) {
				cin >> x;
				switch (x) {
					case '.':
						a[i][j] = 0;
						break;
					case 'X':
						a[i][j] = 1;
						break;
					default:
						a[i][j] = -1;
				}
			}
		}

		int y, min_val = INT_MAX, min_ins = 0;
		set<pi> s;
		REP(i, 0, n) {
			y = 0;
			REP(j, 0, n) {
				if (a[i][j] == -1) {
					y = INT_MAX;
					break;
				}
				else if (a[i][j] == 0)
					++y;
			}
			if (y == 1) {
				int temp = 0;
				REP(ii, 0, n) {
					if (a[i][ii] == 0) {
						temp = ii;
						break;
					}
				}
				s.insert({i, temp});
			}
			if (y == min_val) ++min_ins;
			if (y < min_val) {
				min_val = y;
				min_ins = 1;
			}
		}
		REP(j, 0, n) {
			y = 0;
			REP(i, 0, n) {
				if (a[i][j] == -1) {
					y = INT_MAX;
					break;
				}
				else if (a[i][j] == 0)
					++y;
			}
			if (y == 1) {
				int temp = 0;
				REP(ii, 0, n) {
					if (a[ii][j] == 0) {
						temp = ii;
						break;
					}
				}
				s.insert({temp, j});
			}
			if (y == min_val) ++min_ins;
			if (y < min_val) {
				min_val = y;
				min_ins = 1;
			}
		}

		if (min_val == INT_MAX)
			cout << "Case #" << tt << ": Impossible\n";
		else if (min_val == 1)
			cout << "Case #" << tt << ": 1 " << s.size() << "\n";
		else
			cout << "Case #" << tt << ": " << min_val << " " << min_ins << "\n";
	}

	cout << flush;
}
