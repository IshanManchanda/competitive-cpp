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

	int t;
	cin >> t;
	while (t--) {
		int ax, ay, bx, by, fx, fy;
		cin >> ax >> ay;
		cin >> bx >> by;
		cin >> fx >> fy;

		int ans = abs(by - ay) + abs(bx - ax);

		if (ax == bx && ax == fx) {
			if (ay < fy && fy < by) {
				ans += 2;
			}
			else if (ay > fy && fy > by) {
				ans += 2;
			}
		}
		else if (ay == by && ay == fy) {
			if (ax < fx && fx < bx) {
				ans += 2;
			}
			else if (ax > fx && fx > bx) {
				ans += 2;
			}
		}

		cout << ans << "\n";
	}

	cout << flush;
}
