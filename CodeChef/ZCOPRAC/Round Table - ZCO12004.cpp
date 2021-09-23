#include <bits/stdc++.h>
using namespace std;

long long min(long long a, long long b) { return (a < b) ? a : b; }

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
	dp[n] = a[n - 1] + min(solve(a, n - 1), solve(a, n - 2));
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n;
	cin >> n;
	long long a[n];
	for (long long i = 0; i < n; i++){ cin >> a[i]; }

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	long long m1 = solve(a, n);

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	reverse(a, a + n);

	cout << min(m1, solve(a, n));
}
