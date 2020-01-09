#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long N;
	cin >> N;
	long long a[N + 1], b[N + 1], suffix[N + 1], prefix[N + 1];
	for (long long i = 0; i < N; i++) {
		cin >> a[i];
		b[i] = a[i] + i + 1; // b stores the initial sums
	}

	// Precompute max prefix and suffix arrays
	prefix[0] = b[0];
	suffix[N - 1] = b[N - 1];
	for (long long i = 1; i < N; i++) {
		prefix[i] = max(prefix[i - 1], b[i]);
		suffix[N - i - 1] = max(suffix[N - i], b[N - i - 1]);
	}

	cout << suffix[0] << ' '; // Initial max is 0'th element

	for (long long i = 1; i < N; i++) {
		// Partition between (N - i - 1)'th and (N - i)'th terms.
		long long max_from_start = prefix[N - i - 1] + i;
		long long max_from_end = suffix[N - i] + i - N;
		cout << max(max_from_start, max_from_end) << ' ';
	}
	cout << endl;
}
