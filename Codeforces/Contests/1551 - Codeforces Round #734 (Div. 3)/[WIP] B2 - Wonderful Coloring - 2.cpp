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
		cin >> n >> k;

		int a[n], b[n + 1], c[k + 1], d[n + 1];
		REP(i, 0, n + 1) {
			b[i] = 0;
			d[i] = 1;
		}

		REP(i, 0, n) {
			cin >> a[i];
			++b[a[i]];
		}

		sort(b, b + n + 1, greater<>());
		int j, j2, acc;
		for (j = 0; j < n && b[j] > k; ++j) ;
		for (acc = 0, j2 = j; j2 < n; acc += b[j2], ++j2) ;

		REP(i, 1, k + 1)
			c[i] = j + acc / k;

		REP(i, 0, n) {
			if (d[a[i]] > k) {
				cout << "0 ";
				continue;
			}
			int flag = 0;
			REP(l, d[a[i]], k + 1) {
				if (c[l] > 0) {
					cout << l << " ";
					flag = 1;
					--c[l];
					d[a[i]] = l + 1;
					break;
				}
			}
			if (!flag)
				cout << "0 ";
		}
		cout << "\n";
	}

	cout << flush;
}
