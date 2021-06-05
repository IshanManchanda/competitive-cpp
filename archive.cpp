#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, temp, m = 0;
	long long a[100005] = {}, dp[100005] = {};

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		++a[temp];
		m = max(m, temp);
	}

	dp[1] = a[1];
	for (int i = 2; i <= m; ++i)
		dp[i] = max(i * a[i] + dp[i - 2], dp[i - 1]);

	cout << max(dp[m], dp[m - 1]) << endl;
	return 0;
}
