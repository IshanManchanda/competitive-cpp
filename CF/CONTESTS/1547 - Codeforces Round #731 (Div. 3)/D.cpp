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
		int n;
		cin >> n;
		ll a[n], b[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		b[0] = 0;
		for (int i = 1; i < n; ++i) {
			b[i] = 0;
			for (int j = 0; j < 30; ++j) {
				if (a[i - 1] & (1 << j)) {
					if (!(a[i] & (1 << j))) {
						b[i] |= 1 << j;
					}
				}
			}
			a[i] ^= b[i];
		}

		for (int i = 0; i < n; ++i) {
			cout << b[i] << " ";
		}
		cout << "\n";

	}

	cout << flush;
}
