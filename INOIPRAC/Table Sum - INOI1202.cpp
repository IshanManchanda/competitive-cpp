// https://www.codechef.com/INOIPRAC/problems/INOI1202
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, max_from_start, max_from_end;
	cin >> n;

	long long a[n + 1], suffix[n + 1], prefix[n + 1];
	for (auto i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] += i + 1; // Initial sums
	}

	// Precompute max prefix and suffix arrays
	prefix[0] = a[0];
	suffix[n - 1] = a[n - 1];
	for (auto i = 1; i < n; i++) {
		prefix[i] = max(prefix[i - 1], a[i]);
		suffix[n - i - 1] = max(suffix[n - i], a[n - i - 1]);
	}

	cout << suffix[0] << ' '; // Initial max is global max

	for (auto i = 1; i < n; ++i) {
		// Partition between (n - i - 1)'th and (n - i)'th terms.
		max_from_start = prefix[n - i - 1] + i;
		max_from_end = suffix[n - i] + i - n;
		cout << max(max_from_start, max_from_end) << ' ';
	}
	cout << endl;
}
