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


ll exp(ll a, ll b) {
	if (b == 0) return 1;
	return a * exp(a, b - 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	ll l, r;
	cin >> t;
	while (t--) {
		cin >> l >> r;
		ll acc = r - l, i = 1;

		while (exp(10, i) <= r) {
			acc += r / exp(10, i) - l / exp(10, i);
			++i;
		}

		cout << acc << "\n";
	}

	cout << flush;
}
