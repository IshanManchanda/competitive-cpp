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

	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;

		if (n > 1099)
			cout << "YES\n";

		else {
			if (n >= 111 * (n % 11))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	cout << flush;
}
