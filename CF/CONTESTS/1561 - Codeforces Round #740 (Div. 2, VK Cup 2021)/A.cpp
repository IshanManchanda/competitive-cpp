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
		int n, c = 0;
		cin >> n;

		int a[n];
		REP(i, 0, n)
		cin >> a[i];

		while (!is_sorted(a, a+n)) {
			for (int i = c % 2; i <= n - 2; i += 2)
				if (a[i] > a[i + 1])
					swap(a[i], a[i + 1]);

				++c;
		}
		cout << c << "\n";
	}

	cout << flush;
}
