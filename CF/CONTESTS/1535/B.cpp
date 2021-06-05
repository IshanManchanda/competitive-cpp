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

	int t, n, x;

	cin >> t;
	while (t--) {
		cin >> n;
		int a[n], odd = 0, count;

		REP(i, 0, n) {
			cin >> x;
			if (x % 2 == 1) {
				a[odd] = x;
				odd++;
			}
		}
		count = odd * (n - odd) + (n - odd) * (n - odd - 1) / 2;
		REP(i, 0, odd - 1) {
			REP(j, i + 1, odd) {
				if (__gcd(a[i], a[j]) > 1) {
					++count;
				}
			}
		}
		cout << count << "\n";
	}

	cout << flush;
}
