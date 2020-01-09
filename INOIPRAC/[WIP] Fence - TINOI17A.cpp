#include <bits/stdc++.h>
using namespace std;

/*

x = !grid[i][j + 1] + !grid[i][j - 1] + !grid[i + 1][j] + !grid[i - 1][j];

*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n, r, c, x, y, m = -1;
	cin >> r >> c >> n;
	long long dp[r][c];
	int left[r][c];
	bool grid[r][c];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			grid[r][c] = false;
			left[r][c] = c;
			dp[r][c] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		grid[x - 1][y - 1] = true;
	}

	// Initialize bottom row.
	for (int j = 1; j < c; j++) {
		if (grid[0][j]) {
			if (grid[0][j - 1]) { // Connected to patch on left.
				left[0][j] = left[0][j - 1];
				dp[0][left[0][j]] += !grid[1][j]; // Add fences needed by element to the patch's counter.
			}

			else { // Not connected. Add 1 to current as it needs fence on left.
				dp[0][j] = 1 + !grid[1][j];
			}
		}

		else {
			dp[0][left[0][j - 1]] += 1; // Add one to patch on left as it needs fence on right.
		}
	}
	for (int i = 1; i < r - 1; i++) {
		for (int j = 1; j < c; j++) {
			if (grid[i][j]) {
				if (grid[i][j - 1]) {
					left[i][j] = left[i][j - 1];
					dp[i][left[i][j]] += !grid[i + 1][j] + !grid[i - 1][j];
				} else {
					dp[i][j] = 1 + !grid[i + 1][j] + !grid[i - 1][j];
				}
			} else {
				dp[i][left[i][j - 1]] += 1;
			}
		}
	}
	for (int j = 1; j < c; j++) {
		if (grid[n - 1][j]) {
			if (grid[n - 1][j - 1]) {
				left[n - 1][j] = left[n - 1][j - 1];
				dp[n - 1][left[n - 1][j]] += !grid[n - 2][j];
			} else {
				dp[n - 1][j] = 1 + !grid[n - 2][j];
			}
		} else {
			dp[n - 1][left[n - 1][j - 1]] += 1;
		}
	}

	for (int i = 1; i < r; i++) {
		int j = 1;
		while (j < c) {
			set<int> s;
			while (j < c && left[i][j] == left[i][j - 1]) {
				if (grid[i - 1][j]) {
					if (s.find(left[i - 1][j]) != s.end()) {
						s.insert(left[i - 1][j]);
						left[i][j] += left[i - 1][j];
					}
				}
				j++;
			}
			m = max(m, left[i][j - 1]);
		}
	}

	cout << m;
}
