#include <bits/stdc++.h>
using namespace std;

# define INF 100000001

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int C, x, y;
	long long F, p, m = 0;
	cin >> C >> F;

	long long graph[C + 1][C + 1];
	for (long long i = 0; i < C; i++)
		for (long long j = 0; j < C; j++)
			graph[i][j] = INF;

	for (long long i = 0; i < C; i++)
		graph[i][i] = 0;

	for (long long i = 0; i < F; i++) {
		cin >> x >> y >> p;
		graph[x - 1][y - 1] = p;
		graph[y - 1][x - 1] = p;
	}

	for (long long k = 0; k < C; k++)
		for (long long i = 0; i < C; i++)
			for (long long j = 0; j < C; j++)
				if ((graph[i][k] != INF) && (graph[k][j] != INF))
					if (graph[i][k] + graph[k][j] < graph[i][j])
						graph[i][j] = graph[i][k] + graph[k][j];

	for (long long i = 0; i < C; i++)
		for (long long j = 0; j < C; j++)
			if (graph[i][j] != INF)
				m = max(m, graph[i][j]);

	cout << m << endl;

}
