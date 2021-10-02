#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n, m;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		string names[n];
		int ages[n];
		int people[m];
		for (int i = 0; i < n ; i++) {
			cin >> names[i] >> ages[i];
		}
		int i = 0, j = n - 1;
		while (i + n - j - 1 < m) {
			if (ages[i] < ages[j]) {

			}
		}
	}

}
