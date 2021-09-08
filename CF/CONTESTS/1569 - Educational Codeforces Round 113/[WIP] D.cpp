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
		int n, m, k, temp, temp2, ctr = 0;
		cin >> n >> m >> k;
		vi vert, hor;
		vector<pi> ph, pv;
		REP(i, 0, n) {
			cin >> temp;
			vert.PB(temp);
		}
		REP(i, 0, m) {
			cin >> temp;
			hor.PB(temp);
		}

		REP(i, 0, k) {
			cin >> temp >> temp2;

			if (*lower_bound(vert.begin(), vert.end(), temp) == temp) {
				if (*lower_bound(hor.begin(), hor.end(), temp2) == temp2) {
					continue;
				}
				pv.PB(make_pair(temp2, temp));
			}
			else if (*lower_bound(hor.begin(), hor.end(), temp2) == temp2) {
				ph.PB(make_pair(temp, temp2));
			}
		}
		sort(ph.begin(), ph.end());
		sort(pv.begin(), pv.end());

		REP(i, 0, pv.size()) {
			auto y1 = *(lower_bound(hor.begin(), hor.end(), pv[i]) - 1);
			auto y2 = *upper_bound(hor.begin(), hor.end(), pv[i]);
//			--y1;
			auto x1 = lower_bound(pv.begin(), pv.end(), y1) - pv.begin();
			auto x2 = upper_bound(pv.begin(), pv.end(), y2) - pv.begin() - 1;
//			ctr += (x2 - vert.begin()) - (x1 - vert.begin());
			ctr += (x2 - x1);
		}

		REP(i, 0, ph.size()) {
			auto x1 = *(lower_bound(vert.begin(), vert.end(), ph[i]) - 1);
			auto x2 = *upper_bound(vert.begin(), vert.end(), ph[i]);
//			--x1;
			auto y1 = lower_bound(ph.begin(), ph.end(), x1) - ph.begin();
			auto y2 = upper_bound(ph.begin(), ph.end(), x2) - ph.begin() - 1;
//			ctr += (y2 - hor.begin()) - (y1 - hor.begin());
			ctr += (y2 - y1);
		}
		cout << ctr / 2 << "\n";
	}

	cout << flush;
}
