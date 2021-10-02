#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, s = 0;
	cin >> n;
	long long a[n];
	for (long long i = 0; i < n; i++){ cin >> a[i]; }
	sort(a, a + n);

	for (long long i = 0; i < n; i++) {
		s += a[i] * ((2 * i) - n + 1);
	}
	cout << s;
}
