#include <bits/stdc++.h>
using namespace std;


vector<long long> id[300];
vector<int> e[300];
bool visited[300];
long long rel = 0;


void dfs(int i) {
	if (visited[i]) {
		return;
	}
	visited[i] = true;
	rel++;
	for (int j: e[i]) {
		dfs(j);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K, p, temp;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		visited[i] = false;
		cin >> p;
		while (p--) {
			cin >> temp;
			id[i].push_back(temp);
		}
		sort(id[i].begin(), id[i].end());
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int l = 0, r = 0, c = 0;
			while (l < id[i].size() && r < id[j].size()) {

				if (id[i][l] == id[j][r]) {
					c++; l++; r++;
				} else if (id[i][l] < id[j][r]) {
					l++;
				} else { r++; }

				if (c >= K) {
					e[i].push_back(j);
					e[j].push_back(i);
					break;
				}
			}
		}
	}
	dfs(0);
	cout << rel << endl;
}
