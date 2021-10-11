#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB emplace_back
#define MP make_pair
#define MT make_tuple

#define REP(i,a,b) for (ll i = (a); i < (b); ++i)
#define RREP(i,a,b) for (ll i = (a); i > (b); --i)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define FILE_IN freopen("input.txt", "r", stdin);
#define FILE_OUT freopen("output.txt", "w", stdout);
#define TESTCASES ll tt; cin >> tt; while (tt--)
#define TESTCASES1 ll tt; cin >> tt; REP(ttt, 1, tt + 1)

#define NEG_INF (-LLONG_MAX)
#define FLOAT_EQ(a, b) (abs((a) - (b)) < 1e-9)
#define NEWL "\n";

typedef long long ll;
//typedef __int128_t lll;
//typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<int> vl;
typedef vector<vi> vvl;


int main() {
	FAST_IO

	TESTCASES {
		int n, flag = 0, ctr = 0;
		cin >> n;
		char a[n], b[n][n];
		REP(i, 0, n) cin >> a[i];
		REP(i, 0, n) REP(j, 0, n) b[i][j] = '0';
		REP(i, 0, n) b[i][i] = 'X';
		REP(i, 0, n) {
			if (a[i] == '1') {
				++ctr;
				REP(j, 0, n) {
					if (j == i) continue;
					b[i][j] = '=';
					b[j][i] = '=';
				}
			}
		}
		if ((n - ctr) == 1 || (n - ctr) == 2) {
			cout << "NO\n";
			continue;
		}

		REP(i, 0, n) {
			if (a[i] == '2') {
				if (!flag) {
					REP(j, 0, n) {
						if (i == j) continue;
						if (a[j] == '2') {
							if (!flag) {
								flag = 1;
								b[i][j] = '+';
								b[j][i] = '-';
							}
							else {
								b[i][j] = '-';
								b[j][i] = '+';
							}
						}
					}
				}
				else {
					REP(j, 0, n) {
						if (b[i][j] == '0') {
							b[i][j] = '+';
							b[j][i] = '-';
						}
					}
				}
			}
		}

		cout << "YES\n";
		REP(i, 0, n) {
			REP(j, 0, n) cout << b[i][j];
			cout << "\n";
		}
	}

	cout << flush;
}
