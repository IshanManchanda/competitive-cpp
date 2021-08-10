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
		int n, k;
		cin >> n;
		string s[n];
		int x[n][5], a[n], b[n], c[n], d[n], e[n];
		REP(i, 0, n) {
			cin >> s[i];
			x[i][0] = x[i][1] = x[i][2] = x[i][3] = x[i][4] = 0;
			REP(j, 0, s[i].length()) {
				++x[i][s[i][j] - 'a'];
			}
			a[i] = x[i][0] - x[i][1] - x[i][2] - x[i][3] - x[i][4];
			b[i] = x[i][1] - x[i][0] - x[i][2] - x[i][3] - x[i][4];
			c[i] = x[i][2] - x[i][0] - x[i][1] - x[i][3] - x[i][4];
			d[i] = x[i][3] - x[i][0] - x[i][1] - x[i][2] - x[i][4];
			e[i] = x[i][4] - x[i][0] - x[i][1] - x[i][2] - x[i][3];
		}
		sort(a, a + n, greater<>());
		sort(b, b + n, greater<>());
		sort(c, c + n, greater<>());
		sort(d, d + n, greater<>());
		sort(e, e + n, greater<>());

		int j, max_j = 0, acc;
		if (a[0] > 0) {
			for (j = 1, acc = a[0]; j < n && acc > 0; acc += a[j], ++j);
			if (acc <= 0) --j;
			max_j = max(max_j, j);
		}
		if (b[0] > 0) {
			for(j = 1, acc = b[0]; j < n && acc > 0; acc += b[j], ++j) ;
			if (acc <= 0) --j;
			max_j = max(max_j, j);
		}
		if (c[0] > 0) {
			for(j = 1, acc = c[0]; j < n && acc > 0; acc += c[j], ++j) ;
			if (acc <= 0) --j;
			max_j = max(max_j, j);
		}
		if (d[0] > 0) {
			for(j = 1, acc = d[0]; j < n && acc > 0; acc += d[j], ++j) ;
			if (acc <= 0) --j;
			max_j = max(max_j, j);
		}
		if (e[0] > 0) {
			for(j = 1, acc = e[0]; j < n && acc > 0; acc += e[j], ++j) ;
			if (acc <= 0) --j;
			max_j = max(max_j, j);
		}
		cout << max_j << "\n";
	}

	cout << flush;
}
