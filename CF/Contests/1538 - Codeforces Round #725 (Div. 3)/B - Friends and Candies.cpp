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

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int a[n];
		ll candy_sum = 0;
		REP(i, 0, n) {
			cin >> a[i];
			candy_sum += a[i];
		}

		if (candy_sum % n != 0) {
			cout << "-1\n";
			continue;
		}

		int excess = 0;
		int avg = candy_sum / n;
		REP(i, 0, n) {
			if (a[i] > avg)
				++excess;
		}

		cout << excess << "\n";
	}

	cout << flush;
}
