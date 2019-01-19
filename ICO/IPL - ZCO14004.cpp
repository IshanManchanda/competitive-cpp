#include <bits/stdc++.h>
using namespace std;

long long min(long long a, long long b) { return (a < b) ? a : b; }
long long min(long long a, long long b, long long c) { return min(min(a, b), min(a, c)); }

long long dp[200001];

long long solve(long long a[], long long n) {
	if (dp[n] != -1) {
		return dp[n];
	}
	if (n == 1) {
		dp[1] = a[0];
		return dp[1];
	}
	if (n == 2) {
		dp[2] = a[1];
		return dp[2];
	}
	if (n == 3) {
		dp[3] = a[2];
		return dp[3];
	}
	dp[n] = a[n - 1] + min(solve(a, n - 1), solve(a, n - 2), solve(a, n - 3));
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(dp, -1, sizeof(dp));

	dp[0] = 0;
	long long n;
	cin >> n;
	long long a[n];
	for (long long i = 0; i < n; i++){ cin >> a[i]; }

	solve(a, n);
	long long sum  = 0;
	sum = accumulate(a, a+n, sum);
	cout << sum - min(dp[n - 2], dp[n - 1], dp[n]);
}
