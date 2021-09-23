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
		int k, n, m;
		cin >> k >> n >> m;
		int a[n], b[m], c[n + m];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < m; ++i)
			cin >> b[i];

		int i = 0, j = 0;
		while (i + j < n + m) {
			if (i < n && a[i] <= k) {
				if (a[i] == 0) ++k;
				c[i + j] = a[i];
				++i;
			}
			else if (j < m && b[j] <= k) {
				if (b[j] == 0) ++k;
				c[i + j] = b[j];
				++j;
			}
			else {
				cout << "-1\n";
				break;
			}
		}
		if (i + j == n + m) {
			for (int l = 0; l < n + m; ++l) {
				cout << c[l] << " ";
			}
			cout << "\n";
		}
	}

	cout << flush;
}
