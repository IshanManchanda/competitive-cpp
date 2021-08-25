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
		int n;
		cin >> n;
		int a[n];
		REP(i, 0, n)
		cin >> a[i];

		int c = 0, x;
		while (!sorted(a, n)) {
			++c;
			if (c % 2 == 1) {
				for (int i = 0; i <= n - 3; i += 2) {
					if (a[i] > a[i + 1]) {
						x = a[i];
						a[i] = a[i + 1];
						a[i + 1] = x;
					}
				}
			}
			else {
				for (int i = 1; i <= n - 2; i += 2) {
					if (a[i] > a[i + 1]) {
						x = a[i];
						a[i] = a[i + 1];
						a[i + 1] = x;
					}
				}
			}
		}
		cout << c << "\n";
	}

	cout << flush;
}
