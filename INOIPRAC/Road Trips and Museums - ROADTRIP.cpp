#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, N, M, K, u, v, sum, size, c;
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		int mus[N + 1];
		vector<int> adj[N + 1], vec;
		bool visited[N + 1];
		queue<int> q;

		for (int i = 0; i < M; i++) {
			cin >> u >> v;
			u--; v--;
			adj[v].push_back(u);
			adj[u].push_back(v);
		}

		for (int i = 0; i < N; i++){
			cin >> mus[i];
			visited[i] = false;
		}
		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			q.push(i);
			visited[i] = true;
			vec.push_back(0);
			vec[vec.size() - 1] += mus[i];
			while (!q.empty()) {
				c = q.front();
				q.pop();
				for (int j : adj[c]) {
					if (!visited[j]) {
						q.push(j);
						visited[j] = true;
						vec[vec.size() - 1] += mus[j];
					}
				}
			}
		}
		size = vec.size();
		if (vec.size() < K) {
			cout << "-1" << endl;
			continue;
		}
		sort(vec.begin(), vec.end());

		if (K % 2) {
			sum = vec[size - 1];
			for (int i = 0; i < (K / 2); i++) {
				sum += vec[i] + vec[size - i - 2];
			}
		} else {
			sum = 0;
			for (int i = 0; i < (K / 2); i++) {
				sum += vec[i] + vec[size - i - 1];
			}
		}
		cout << sum << '\n';

	}
}
