#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = (a); i < (b); ++i)

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
		ll a[2 * n + 1];
		REP(i, 0, 2 * n) {
			cin >> a[i];
		}

		sort(a, a + 2 * n);
		REP(i, 0, n) {
			cout << a[i] << " " << a[i + n] << " ";
		}
		cout << "\n";
	}
	cout << flush;
}
