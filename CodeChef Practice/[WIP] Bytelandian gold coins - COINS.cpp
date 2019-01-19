#include <bits/stdc++.h>
using namespace std;


long long solve(long long n, long long a[]) {
	if (n < 2) {
		return n;
	}
	if (a[n - 1] != 0) {
		return a[n];
	}
	return a[n - 1] = max(n, solve(n / 2, a) + solve(n / 3, a) + solve(n / 4, a));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n;
	while (cin >> n) {
		long long a[n];
		for (long long i = 0; i < n; i++) {
			a[i] = 0;
		}
		cout << solve(n, a) << endl;
	}
}
