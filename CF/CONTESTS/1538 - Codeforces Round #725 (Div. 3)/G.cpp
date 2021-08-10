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

ll x, y, a, b, temp;

bool check(ll n) {
	if (n == 0) return true;
	if (a == b) return n * a <= y;

	if ((x - n * b) >= 0) {
		if ((n * a - y) <= (n * (a - b))) {
			if ((int ((x - n * b) / (a - b))) >= ((n * a - y) / (a - b))) {
				return true;
			}
		}
	}

	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> x >> y >> a >> b;
		if (x < y) {
			temp = x;
			x = y;
			y = temp;
		}
		if (a < b) {
			temp = a;
			a = b;
			b = temp;
		}

		ll lower = 0, upper = 1 + min(y / b, x / a);
		while (lower < upper) {
			ll mid = lower + (upper - lower) / 2;

			if (check(mid))
				lower = mid + 1;
			else
				upper = mid - 1;
		}
		if (check(upper)) cout << upper << "\n";
		else cout << upper - 1 << "\n";
	}

	cout << flush;
}
