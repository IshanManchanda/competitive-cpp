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
		string s;
		cin >> s;
		int a = 0, b = 0, cs[26];
		REP(i, 0, 26)
			cs[i] = 0;

		REP(i, 0, s.length()) {
			++cs[s[i] - 'a'];
		}

		REP(i, 0, 26) {
			if (cs[i] >= 2)
				++a;
			if (cs[i] == 1) {
				if (b == 1) {
					b = 0;
					++a;
				} else {
					b = 1;
				}
			}
		}

		cout << a << "\n";

	}

	cout << flush;
}
