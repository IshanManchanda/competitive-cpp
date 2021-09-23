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
	cin >> n;
	ll a[n + 2], prev[n + 2], cur[n + 2], min_check = 0;

	REP(i, 0, n) {
		cin >> a[i + 1];
	}

	prev[0] = 0;

	REP(i, 1, n + 1) {

		if ((prev[i - 1] == NEG_INF) || ((prev[i - 1] + a[i]) < 0)) {
			cur[i] = NEG_INF;
		} else {
			cur[i] = prev[i - 1] + a[i];
		}

		RREP(j, i - 1, min_check) {
			if ((prev[j - 1] == NEG_INF) || ((prev[j - 1] + a[i]) < 0)) {
				cur[j] = prev[j];
			}
			else {
				cur[j] = max(prev[j - 1] + a[i], prev[j]);
			}
		}
		ll m = -1;
		REP(j, min_check, i + 1) {
			if (cur[j] >= m) {
				m = cur[j];
				min_check = j;
			}
		}
		REP(j, min_check, i + 1) {
			prev[j] = cur[j];
		}
		prev[0] = 0;
	}
	RREP(i, n, min_check - 1) {
		if (cur[i] >= 0) {
			cout << i << flush;
			return 0;
		}
	}
	cout << min_check << flush;
}
