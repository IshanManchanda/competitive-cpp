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

	int k, q;
	string s;
	cin >> k >> s >> q;

	reverse(s.begin(), s.end());
	ll n = s.length(), dp[n + 1], p;
	char c;

	REP(i, n / 2, n) {
		dp[i] = (s[i] == '?') ? 2 : 1;
	}
	RREP(i, n / 2 - 1, -1) {
		if (s[i] == '?')
			dp[i] = dp[2 * i + 1] + dp[2 * i + 2];
		else if (s[i] == '1')
			dp[i] = dp[2 * i + 1];
		else
			dp[i] = dp[2 * i + 2];
	}

	REP(i, 0, q) {
		cin >> p >> c;
		p = n - p;
		s[p] = c;

		if (p >= n / 2) {
			dp[p] = (s[p] == '?') ? 2 : 1;
			p = (p - 1) >> 1;
		}

		for (ll j = p; j >= 0; j = (j - 1) >> 1) {
			if (s[j] == '?')
				dp[j] = dp[2 * j + 1] + dp[2 * j + 2];
			else if (s[j] == '1')
				dp[j] = dp[2 * j + 1];
			else
				dp[j] = dp[2 * j + 2];

			if (j == 0) break;
		}
		cout << dp[0] << "\n";
	}

	cout << flush;
}
