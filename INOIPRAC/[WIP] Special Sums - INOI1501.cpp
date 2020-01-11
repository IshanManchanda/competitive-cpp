// https://www.codechef.com/INOIPRAC/problems/INOI1501
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, ans = -2e9;
	cin >> n;

	long long a[n], b[n], d[n], l[n], r[n];
	for (auto i = 0; i < n; ++i) {
		cin >> a[i];
		ans = max(ans, a[i]);
	}

	cin >> b[0];
	d[0] = a[0] - b[0];
	for (auto i = 1; i < n; ++i) {
		cin >> b[i];
		b[i] += b[i - 1];
		d[i] = max(d[i - 1], a[i] - b[i]);
	}

	for (auto i = 1; i < n - 1; ++i) {
		ans = max(ans, a[i] + b[i - 1] + d[i - 1]);
		ans = max(ans, a[i] + b[i - 1] + d[i - 1] + b[n - 1] - b[i]);
	}

	cout << ans << endl;
}
