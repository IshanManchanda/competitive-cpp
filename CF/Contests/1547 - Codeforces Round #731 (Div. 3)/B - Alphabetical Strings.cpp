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

		if (s.length() == 1) {
			cout << ((s == "a") ? "YES\n" : "NO\n");
			continue;
		}

		int a = 0;
		for (; a < s.length() && s[a] != 'a'; ++a) ;
		if (a == s.length()) {
			cout << "NO\n";
			continue;
		}

		int p1 = a - 1, p2 = a + 1, c = 1;
		while (p2 - p1 <= s.length()) {
			if (p1 >= 0 && s[p1] == ('a' + c)) {
				--p1;
				++c;
			}
			else if (p2 < s.length() && s[p2] == ('a' + c)) {
				++p2;
				++c;
			}
			else {
				cout << "NO\n";
				break;
			}
		}
		if (p2 - p1 > s.length()) {
			cout << "YES\n";
		}
	}

	cout << flush;
}
