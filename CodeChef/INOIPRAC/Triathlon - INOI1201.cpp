// https://www.codechef.com/INOIPRAC/problems/INOI1201
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, x, y, z, tm = 0, tc = 0;
	cin >> n;

	pair<long long, long long> t[n];
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> z;
		t[i] = {y + z, x};
	}

	sort(t, t + n, greater<>());
	for (int i = 0; i < n; ++i) {
		tc += t[i].second;
		tm = max(tm, tc + t[i].first);
	}

	cout << tm << endl;
}
