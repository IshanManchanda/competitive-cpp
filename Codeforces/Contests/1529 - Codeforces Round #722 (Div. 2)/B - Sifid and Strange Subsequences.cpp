#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = (a); i < (b); ++i)

typedef long long ll;
//typedef __int128_t lll;
typedef pair<int,int> pi;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll t, min_dif, min_temp, n;
	cin >> t;

	REP(i, 0, t) {
		cin >> n;
		ll a[n + 1];
		min_dif = LLONG_MAX;

		REP(j, 0, n)
			cin >> a[j];
		sort(a, a + n);

		int j = 0;
		while (j < n - 1) {
			min_temp = min(min_dif, a[j + 1] - a[j]);
			if (min_temp >= a[j + 1]) ++j;
			else break;
			min_dif = min_temp;
		}
		cout << j + 1 << "\n";
	}
	cout << flush;
}
