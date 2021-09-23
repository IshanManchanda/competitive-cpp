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
		int n, m, k;
		cin >> n >> m >> k;
		if (n % 2 == 0 && m % 2 == 0) {
			cout << "YES\n";
			continue;
		}
		if (n % 2 == 0) {
			if (((n * m / 2) - k) < (n / 2)) {
				cout << "NO\n";
				continue;
			}
			if ((((n * m / 2) - k) - (n / 2)) % 2 == 0) {
				cout << "YES\n";
				continue;
			}
			cout << "NO\n";
			continue;
		}
		if (k < (m / 2)) {
			cout << "NO\n";
			continue;
		}
		if ((k - m / 2) % 2 == 0) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}

	cout << flush;
}
