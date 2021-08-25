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


int sorted(int* a, int n) {
	REP(i, 0, n - 1) {
		if (a[i] > a[i + 1])
			return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n;
		pi a[n];
		REP(i, 0, n) {
			a[i] = {0, 0};
			cin >> a[i].S;
			REP(j, 0, a[i].S) {
				cin >> k;
				a[i].F = max(a[i].F, (int)(k - j));
			}
		}
		sort(a, a+n);
		int x = -1, inc = 0;
		REP(i, 0, n) {
			x = max(x, a[i].F - inc);
			inc += a[i].S;
		}
		cout << x + 1 << "\n";
	}

	cout << flush;
}
