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
		int l, r;
		cin >> l >> r;

		if ((2 * l) <= (r - 1))
			cout << (r - 1) / 2 << "\n";
		else if ((2 * l) == r)
			cout << r / 2 - 1 << "\n";
		else
			cout << (r - l) << "\n";
	}

	cout << flush;
}
