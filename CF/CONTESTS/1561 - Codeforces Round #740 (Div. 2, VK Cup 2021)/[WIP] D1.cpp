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

	int n, m;
	ll x;
	cin >> n >> m;
	int a[n + 1], b[n + 1];
	a[1] = 1;
	b[1] = 1;
	REP(i, 2, n + 1) {
		a[i] = b[i - 1];

		REP(j, 2, i / 2 + 1) {
			x = a[i] + a[i / j];
			a[i] = (x >= m) ? x - m: x;
		}

		x = a[i] + (i - (int)(i / 2));
		a[i] = (x >= m) ? x - m: x;
		x = b[i - 1] + a[i];
		b[i] = (x >= m) ? x - m: x;
	}
	cout << a[n] << flush;
}
