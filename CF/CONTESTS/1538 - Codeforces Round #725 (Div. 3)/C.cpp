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

	int t, n;
	ll l, r;
	cin >> t;
	while (t--) {
		cin >> n >> l >> r;
		ll a[n];

		REP(i, 0, n) {
			cin >> a[i];
		}

		sort(a, a + n);

		ll acc = 0;
		REP(i, 0, n) {
			ll alpha = upper_bound(a, a + n, r - a[i]) - a;
			ll beta = lower_bound(a, a + n, l - a[i]) - a;
			if (beta <= i && i < alpha)
				alpha--;
			acc += alpha - beta;
		}

		cout << acc / 2 << "\n";
	}

	cout << flush;
}
