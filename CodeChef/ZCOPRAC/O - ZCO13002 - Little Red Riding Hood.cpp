/*
#include <bits/stdc++.h>
using namespace std;


const long long inf = 2000000000000;
const long long neg_inf = -inf;
long long charm[501][501], grid[501][501], memo[501][501];


long long solve(long long i, long long j) {
	if (!charm[i][j]) return neg_inf;
	if (memo[i][j] != neg_inf) return memo[i][j];

	if (i == 1) {
		if (j == 1) return memo[i][j] = grid[1][1] + max(memo[0][1], memo[1][0]);
		return memo[i][j] = grid[1][j] + max(charm[0][j], solve(1, j - 1));
	}
	if (j == 1) return memo[i][j] = grid[i][1] + max(charm[i][0], solve(i - 1, 1));

	return memo[i][j] = grid[i][j] + max(solve(i - 1, j), solve(i, j - 1));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long N, M, cx, cy, cs;
	cin >> N >> M;
	for (long long i = 0; i < N; i++) {
		for (long long j = 0; j < N; j++) {
			cin >> grid[i][j];
			charm[i][j] = 0;
			memo[i][j] = neg_inf;
		}
	}

	for (long long k = 0; k < M; k++) {
		cin >> cx >> cy >> cs;
		cx--; cy--;
		for (long long i = max(0LL, cx - cs); i <= min(N - 1, cx + cs); i++) {
			for (long long j = max(0LL, cy - cs + abs(cx - i)); j <= min(N - 1, cy + cs - abs(cx - i)); j++) {
				charm[i][j] = 1;
			}
		}
	}
	if (!charm[0][0] || !charm[N - 1][N - 1]) {
		cout << "NO" << endl;
		return 0;
	}
	memo[0][0] = grid[0][0];
	for (long long i = 1; i < N; i++) {
		if (!charm[i][0]) {
			break;
		}
		memo[i][0] = grid[i][0] + memo[i - 1][0];
	}
	for (long long j = 1; j < N; j++) {
		if (!charm[0][j]) {
			break;
		}
		memo[0][j] = grid[0][j] + memo[0][j - 1];
	}

	solve(N - 1, N - 1);
	if (memo[N - 1][N - 1] < (neg_inf / 2)) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES\n";
	cout << memo[N - 1][N - 1] << endl;
}

*/


















//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; ++j) {
//			cout << memo[i][j] << ' ';
//		}
//		cout << endl;
//	}


#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long inf = 2000000000000;
	long long neg_inf = -inf;

	long long N, M, cx, cy, cs;
	cin >> N >> M;
	long long charm[N][N], grid[N][N], memo[N][N];
	for (long long i = 0; i < N; i++) {
		for (long long j = 0; j < N; j++) {
			cin >> grid[i][j];
			charm[i][j] = 0;
			memo[i][j] = neg_inf;
		}
	}

	for (long long k = 0; k < M; k++) {
		cin >> cx >> cy >> cs;
		cx--; cy--;
		for (long long i = max(0LL, cx - cs); i <= min(N - 1, cx + cs); i++) {
			for (long long j = max(0LL, cy - cs + abs(cx - i)); j <= min(N - 1, cy + cs - abs(cx - i)); j++) {
				charm[i][j] = 1;
			}
		}
	}
	memo[0][0] = grid[0][0];
	for (long long i = 1; i < N; i++) {
		if (!charm[i][0]) {
			break;
		}
		memo[i][0] = grid[i][0] + memo[i - 1][0];
	}
	for (long long j = 1; j < N; j++) {
		if (!charm[0][j]) {
			break;
		}
		memo[0][j] = grid[0][j] + memo[0][j - 1];
	}

	for (long long i = 1; i < N; i++) {
		for (long long j = 1; j < N; j++) {
			if (charm[i][j]) {
				if ((memo[i][j - 1] != neg_inf) || (memo[i - 1][j] != neg_inf)) {
					memo[i][j] = grid[i][j] + max(memo[i - 1][j], memo[i][j - 1]);
				}
			}
		}
	}

	if (memo[N - 1][N - 1] < (neg_inf / 2)) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES\n";
	cout << memo[N - 1][N - 1] << endl;
}
