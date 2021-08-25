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
		int a, b;
		cin >> a >> b;

		if (a == b) {
			cout << a + 1 << "\n";
			for (int i = 0; i <= 2 * a; i += 2)
				cout << i << " ";
			cout << "\n";
			continue;
		}
		if (abs(a - b) == 1) {
			cout << a + b + 1 << "\n";
			for (int i = 0; i <= a + b; ++i)
				cout << i << " ";
			cout << "\n";
			continue;
		}
		int x;
		if (a < b) {
			x = a;
			a = b;
			b = x;
		}
		x = a - b;
		if (x % 2 == 0) {
			cout << b + 1 << "\n";
			for (int i = x / 2; i <= 2 * b + x / 2; i += 2)
				cout << i << " ";
			cout << "\n";
		}
		else {
			cout << 2 * b + 2 << "\n";
			for (int i = x / 2; i <= 2 * b + x / 2 + 1; ++i)
				cout << i << " ";
			cout << "\n";
		}
	}

	cout << flush;
}
