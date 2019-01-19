#include <bits/stdc++.h>
using namespace std;

int N, E[5000];
long long grid[5000][5000], inc[5001];


long long increment(long long n) {
	long long a = 0;
	while (n > 0) {
		a += n % 10;
		n /= 10;
	}
	return a * a * a;
}


long long solve(long long city, long long t) {
	if (grid[city][t] != -1) return grid[city][t];

	if (city == N - 1) return grid[city][t] = inc[t] * E[city];

	return grid[city][t] = max(
			inc[t] * E[city] + solve(city + 1, t),
			solve(city + 1, t + 1)
	);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> inc[0];
	for (int i = 0; i < N; i++) {
		cin >> E[i];
		inc[i + 1] = inc[i] + increment(inc[i]);
		for (int j = 0; j < N; j++) {
			grid[i][j] = -1;
		}
	}
	cout << solve(0, 0) << endl;
}
