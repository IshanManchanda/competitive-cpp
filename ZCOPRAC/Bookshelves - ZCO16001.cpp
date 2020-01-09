#include <bits/stdc++.h>
using namespace std;

long long min(long long a, long long b) { return (a < b) ? a : b; }

long long solve(long long a[], long long b[], long long n, long long k) {
	for (long long i = 0; i < k; i++) {
		if (a[n - 1] >= b[0]) {
			break;
		}
		long long t = b[0];
		b[0] = a[n - 1];
		a[n - 1] = t;
		sort(a, a + n, greater<>());
		sort(b, b + n, greater<>());
	}
	return a[0] + b[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, k;
	cin >> n >> k;
	long long a[n], b[n], c[n], d[n];

	for (long long i = 0; i < n; i++){ cin >> a[i]; }
	for (long long i = 0; i < n; i++){ cin >> b[i]; }

	sort(a, a + n, greater<>());
	sort(b, b + n, greater<>());

	for (long long i = 0; i < n; i++){ c[i] = a[i]; }
	for (long long i = 0; i < n; i++){ d[i] = b[i]; }

	cout << min(solve(a, b, n, k), solve(d, c, n, k));
}
