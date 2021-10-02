#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, N, M, u, v, tl, tr, bl, br, m;
	cin >> t;

	while (t--) {
		m = 0;
		cin >> N >> M;
		int a[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < M; i++) {
			cin >> u >> v;
			a[u - 1][v - 1] = 1;
		}

		for (int i = 1; i < N; i++) {
			a[i][0] += a[i - 1][0];
			a[0][i] += a[0][i - 1];
		}
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			}
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < N - 1; j++) {
				tl = a[i][j];
				tr = a[N - 1][j] - tl;
				bl = a[i][N - 1] - tl;
				br = M - tr - bl - tl;
				m = max(m, min(min(tl, tr), min(bl, br)));
			}
		}
		cout << m << endl;
	}
}
