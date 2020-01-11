#include <bits/stdc++.h>
using namespace std;

#define NEG_INF -2e9

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, k, ans = NEG_INF;
	cin >> n >> k;
	k--;

	long long a[n], f[n], b[n];
	for (auto i = 0; i < n; ++i)
		cin >> a[i];

	b[0] = a[0];
	b[1] = a[1] + a[0];
	for (auto i = 2; i < n; ++i)
		b[i] = a[i] + max(b[i - 1], b[i - 2]);

	f[k] = 0;
	f[k + 1] = a[k + 1];
	for (auto i = k + 2; i < n; ++i)
		f[i] = a[i] + max(f[i - 1], f[i - 2]);

	for (auto i = k; i < n; ++i)
		ans = max(ans, f[i] + b[i] - a[i]);

	cout << ans << endl;
}
