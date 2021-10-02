#include <bits/stdc++.h>
using namespace std;

#define NEG_INF -1000000000001
long long grid[1000][1000], dp_min[1000][1000][20], dp_max[1000][1000][20];


long long compute_max(int r, int c, int k) {
	if (r == 0) return grid[0][c];
	if (dp_max[r][c][k] != NEG_INF) return dp_max[r][c][k];

	if (k == 0 || c == 0) {
		long long temp = 0, row = r;
		while (row >= 0) {
			temp += grid[row][c];
			row--;
		}
		return dp_max[r][c][k] = temp;
	}
	return dp_max[r][c][k] = grid[r][c] + max(compute_max(r - 1, c, k), compute_max(r - 1, c - 1, k - 1));
}

long long compute_min(int r, int c, int k) {
	if (c == 0) return dp_min[r][c][k] = 0;
	if (r == 0) return grid[0][c - 1];
	if (dp_min[r][c][k] != NEG_INF) return dp_min[r][c][k];

	if (k == 0) {
		long long temp = 0, row = r;
		while (row >= 0) {
			temp += grid[row][c - 1];
			row--;
		}
		return dp_min[r][c][k] = temp;
	}
	return dp_min[r][c][k] = grid[r][c - 1] + min(compute_min(r - 1, c, k), compute_min(r - 1, c - 1, k - 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, N, M, K;
	long long m;
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++) {
			cin >> grid[i][0];
			for (int j = 1; j < M; j++) {
				cin >> grid[i][j];
				grid[i][j] += grid[i][j - 1];
			}
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				for (int k = 0; k <= K; k++) {
					dp_min[r][c][k] = NEG_INF;
					dp_max[r][c][k] = NEG_INF;
				}
			}
		}
		for (int j = 0; j < M; j++) {
			compute_min(N - 1, j, K);
			compute_max(N - 1, j, K);
		}
		m = NEG_INF;
		for (int i = 0; i < M - K - 1; i++) {
			for (int j = i + K + 1; j < M; j++) {
				m = max(m, dp_max[N - 1][j][K] - dp_min[N - 1][i][K]);
			}
		}
		cout << m << '\n';
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << dp_min[i][j][1] << ' ';
			} cout << endl;
		} cout << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << dp_max[i][j][1] << ' ';
			} cout << endl;
		}*/
	}
}
