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

int a[300002], t[300002];

bool comp(int x, int y) {
	return a[x] + t[x] < a[y] + t[y];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		REP(i, 0, k) {
			cin >> a[i];
			--a[i];
		}
		REP(i, 0, k)
			cin >> t[i];

		int ids[k], temps[n], pos = 0, ac_pos = 0, left = 0;
		REP(i, 0, k)
			ids[i] = i;
		sort(ids, ids + k, comp);

		while (pos < n) {
			for (; pos <= a[ids[ac_pos]]; ++pos) {
				temps[pos] = t[ids[ac_pos]] + a[ids[ac_pos]] - pos;
				temps[pos] = min(temps[pos], t[ids[left]] + abs(pos - a[ids[left]]));
			}
			while (ac_pos < k && a[ids[ac_pos]] < pos) {
				if (t[ids[left]] + abs(pos - a[ids[left]]) > t[ids[ac_pos]] + abs(pos - a[ids[ac_pos]])) {
					left = ac_pos;
				}
				++ac_pos;
			}
			if (ac_pos == k) {
				while (pos < n) {
					temps[pos] = t[ids[left]] + abs(pos - a[ids[left]]);
					++pos;
				}
			}
		}

		REP(i, 0, n)
			cout << temps[i] << " ";
		cout << "\n";
	}

	cout << flush;
}
