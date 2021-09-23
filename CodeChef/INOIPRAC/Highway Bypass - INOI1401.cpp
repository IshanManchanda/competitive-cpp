// https://www.codechef.com/INOIPRAC/problems/INOI1401
#include <bits/stdc++.h>
using namespace std;

#define MOD 20011

int r, c, d;
long long grid[301][301][301][2];
bool roads[301][301];

long long solve(int i, int j, int d1, bool down) {
	if (!roads[i][j])
		return 0;

	if (grid[i][j][d1][down] != -1)
		return grid[i][j][d][down];

	if (i == 0 || j == 0)
		return 0;

	// We have already moved the maximum allowable steps in this direction
	if (d1 == 0) {
		if (down)
			// We can only move horizontally
			return grid[i][j][d1][down] =
					solve(i - 1, j, d - 1, false) % MOD;
		else
			return grid[i][j][d1][down] =
					solve(i, j - 1, d - 1, true) % MOD;
	}

	if (down)
		return grid[i][j][d1][down] = (
				solve(i, j - 1, d1 - 1, true) +
				solve(i - 1, j, d - 1, false)) % MOD;
	else
		return grid[i][j][d1][down] = (
				solve(i - 1, j, d1 - 1, false) +
				solve(i, j - 1, d - 1, true)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c >> d;
	// Input roads
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> roads[i][j];

	// Initialize dp grid
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			for (int k = 0; k <= d; ++k) {
				grid[i][j][k][0] = -1;
				grid[i][j][k][1] = -1;
			}
		}
	}

	// Base case: Left most column
	for (int i = 0; i <= d; ++i) {
		if (!roads[i][0])
			break;

		for (int k = 0; k <= d; ++k) {
			grid[i][0][k][0] = 1;
			grid[i][0][k][1] = 1;
		}
	}

	// Base case: Top row
	for (int j = 0; j <= d; ++j) {
		if (!roads[0][j])
			break;

		for (int k = 0; k <= d; ++k) {
			grid[0][j][k][0] = 1;
			grid[0][j][k][1] = 1;
		}
	}

	cout << solve(r - 1, c - 1, d, true) << endl;
}
