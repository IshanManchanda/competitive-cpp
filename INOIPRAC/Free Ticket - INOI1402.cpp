#include <bits/stdc++.h>
using namespace std;

#define INF ((unsigned) ~0)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, f, x, y, p, ans = 0;
	cin >> n >> f;

	long long dist[n + 1][n + 1];
	for (long long i = 0; i < n; ++i)
		for (long long j = 0; j < n; ++j)
			dist[i][j] = INF;

	for (long long i = 0; i < n; ++i)
		dist[i][i] = 0;

	for (int i = 0; i < f; ++i) {
		cin >> x >> y >> p;
		dist[x - 1][y - 1] = p;
		dist[y - 1][x - 1] = p;
	}

	for (long long k = 0; k < n; ++k)
		for (long long i = 0; i < n; ++i)
			for (long long j = 0; j < n; ++j)
				if (dist[i][k] != INF and dist[k][j] != INF)

					if (dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];

	for (long long i = 0; i < n; ++i)
		for (long long j = 0; j < i; ++j)
			if (dist[i][j] != INF)
				ans = max(ans, dist[i][j]);

	cout << ans << endl;
}
