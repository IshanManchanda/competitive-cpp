#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = (a); i < (b); ++i)
#define RREP(i,a,b) for (int i = (a); i > (b); --i)

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
	string s;
	cin >> t;
	getline(cin, s);
	while (t--) {
		getline(cin, s);
		int l = s.length();
		ll dp[l], acc;

		acc = dp[0] = 1;
		REP(i, 1, l) {
			if (s[i] == '?') dp[i] = dp[i - 1] + 1;
			else if (s[i - 1] == '?') {
				int j = i - 2;
				while (j >= 0 && s[j] == '?') --j;
				if (j == -1) {
					dp[i] = dp[i - 1] + 1;
				}
				else {
					if ((i - j) % 2 == 0) {
						if (s[i] == s[j]) {
							dp[i] = dp[i - 1] + 1;
						}
						else dp[i] = dp[i - 1] + 1 - dp[j];
					}
					else {
						if (s[i] != s[j]) {
							dp[i] = dp[i - 1] + 1;
						}
						else dp[i] = dp[i - 1] + 1 - dp[j];
					}
				}
			}
			else if (s[i - 1] != s[i]) {
				dp[i] = dp[i - 1] + 1;
			}
			else dp[i] = 1;

			acc += dp[i];
		}
		cout << acc << "\n";
	}

	cout << flush;
}
