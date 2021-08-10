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

	int n, c = 0;
	cin >> n;
	int a[n];

	REP(i, 1, n + 1) {
		if (n % i == 0) {
			a[c] = i;
			++c;
		}
	}

	cout << c << "\n";
	REP(i, 0, c) {
		cout << a[i] << " ";
	}

	cout << flush;
}
