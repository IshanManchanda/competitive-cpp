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

	int n, k, x, y;
	cin >> n;
	tuple<int, int, int> c[n + 1];
	REP(i, 0, n) {
		cin >> x >> y;
		c[i] = {y, x, i + 1};
	}
	cin >> k;
	vector<pi> r;
	REP(i, 0, k) {
		cin >> x;
		r.emplace_back(x, i + 1);
	}

	sort(c, c+n, greater<>());
	sort(r.begin(), r.end());
	int m = 0, s = 0;
	pi t[n];
	REP(i, 0, n) {
		auto lb = lower_bound(r.begin(), r.end(), make_pair(get<1>(c[i]), -1));
		if (lb == r.end()) continue;

		s += get<0>(c[i]);
		t[m] = {get<2>(c[i]), lb->S};
		++m;
		r.erase(lb);
	}
	cout << m << " " << s << "\n";
	REP(i, 0, m)
	cout << t[i].F << " " << t[i].S << "\n";

	cout << flush;
}
