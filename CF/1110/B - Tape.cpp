#include <bits/stdc++.h>
using namespace std;


int dp[3001][100001];
int a[3001];
int n, l;


int solve(int i, int len) {
	if (dp[i][len] != -1) {
		return dp[i][len];
	}

	if (len < 2) return 999999;

	if (len == 2) {
		int i1 = 0, i2 = n - 1;
		while (i1 < n && a[i1] > a[i]) i1++;
		while (i2 >= 0 && a[i2] > a[i]) i2--;

		if (i1 == n && i2 == -1) return -1;
		if (i1 == n) return i2 - i;
		if (i2 == -1) return i - i1;
		return max(i - i1, i2 - i);
	}

	int m = 0;
	for (int in = 0; in < n; in++) {
		if (a[in] <= a[i]) {
			if (abs(in - i) > m) {
				m = max(m, min(abs(in - i), solve(in, len - 1)));
			}
		}
	}

	return dp[i][len] = m;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> l;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int m = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j <= l; j++)
				dp[i][j] = -1;

		for (int i = 0; i < n; i++) {
			m = max(m, solve(i, l));
		}
		cout << m << '\n';
	}
	return 0;
}
