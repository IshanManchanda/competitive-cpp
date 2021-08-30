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
		int k, done = 0;
		cin >> k;
		string s;
		cin >> s;

		REP(i, 0, k) {
			if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
				cout << "1\n" << s[i] << "\n";
				done = 1;
				break;
			}
		}
		if (done) continue;
		REP(i, 1, k) {
			if (s[i] == '2' || s[i] == '5') {
				cout << "2\n" << s[0] << s[i] << "\n";
				done = 1;
				break;
			}
		}
		if (done) continue;
		if (s[0] == '2' || s[0] == '5') {
			REP(i, 1, k) {
				if (s[i] == '7') {
					cout << "2\n" << s[0] << s[i] << "\n";
					done = 1;
					break;
				}
			}
		}
		if (done) continue;
		REP(i, 0, k) {
			if (s[i] == '3') {
				REP(j, i + 1, k) {
					if (s[j] == s[i]) {
						cout << "2\n" << s[i] << s[i] << "\n";
						done = 1;
						break;
					}
				}
				break;
			}
		}
		if (done) continue;
		REP(i, 0, k) {
			if (s[i] == '7') {
				REP(j, i + 1, k) {
					if (s[j] == s[i]) {
						cout << "2\n" << s[i] << s[i] << "\n";
						done = 1;
						break;
					}
				}
				break;
			}
		}
		if (done) continue;
	}

	cout << flush;
}
