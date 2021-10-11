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
		int n;
		cin >> n;
		string s;
		cin >> s;
		ll dp[n + 1], m = n;
		dp[0] = n;
		REP(i, 1, n) {
			dp[i] = n - i;
			REP(j, 0, i) {
				if (s[i] > s[j]) {
					dp[i] = max(dp[i], dp[j] + n - i);
				}
				if (s[i] == s[j]) {
					ll a = i, b = j;
					while (a < n && s[a] == s[b]) {
						++a;
						++b;
					}
					if (a == n) continue;
					if (s[a] > s[b]) {
						dp[i] = max(dp[i], dp[j] + n - a);
					}
				}
			}
			m = max(m, dp[i]);
		}
		cout << m << "\n";
	}

	cout << flush;
}
