#include <bits/stdc++.h>
using namespace std;

int R, C, D;
long long grid[301][301][301][2];
bool roads[301][301];


long long solve(int i, int j, int d, bool down) {
	if (!roads[i][j]) {
		return 0;
	}
	if (grid[i][j][d][down] != -1) {
		return grid[i][j][d][down];
	}
	if (i == 0 || j == 0) {
		return 0;
	}

	if (d == 0) {
		if (down) {
			return grid[i][j][d][down] = solve(i - 1, j, D - 1, false) % 20011;
		} else {
			return grid[i][j][d][down] = solve(i, j - 1, D - 1, true) % 20011;
		}
	}
	if (down) {
		return grid[i][j][d][down] = (solve(i, j - 1, d - 1, true) + solve(i - 1, j, D - 1, false)) % 20011;
	} else {
		return grid[i][j][d][down] = (solve(i - 1, j, d - 1, false) + solve(i, j - 1, D - 1, true)) % 20011;
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C >> D;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> roads[i][j];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k <= D; k++) {
				grid[i][j][k][0] = -1;
				grid[i][j][k][1] = -1;
			}
		}
	}
	for (int i = 0; i <= D; i++) {
		if (!roads[i][0]) {
			break;
		}
		for (int k = 0; k <= D; k++) {
			grid[i][0][k][0] = 1;
			grid[i][0][k][1] = 1;
		}
	}
	for (int j = 0; j <= D; j++) {
		if (!roads[0][j]) {
			break;
		}
		for (int k = 0; k <= D; k++) {
			grid[0][j][k][0] = 1;
			grid[0][j][k][1] = 1;
		}
	}


	cout << solve(R - 1, C - 1, D, true) << endl;
}
