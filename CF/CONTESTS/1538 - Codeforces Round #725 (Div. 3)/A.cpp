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

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int a[n], min_pos = 0, max_pos = 0;
		REP(i, 0, n) {
			cin >> a[i];
			if (a[i] > a[max_pos]) {
				max_pos = i;
			}
			else if (a[i] < a[min_pos]) {
				min_pos = i;
			}
		}

		int min_val = min(1 + max(min_pos, max_pos), n - min(min_pos, max_pos));
		min_val = min(min_val, 1 + min_pos + n - max_pos);
		min_val = min(min_val, 1 + max_pos + n - min_pos);
		cout << min_val << "\n";
	}

	cout << flush;
}
