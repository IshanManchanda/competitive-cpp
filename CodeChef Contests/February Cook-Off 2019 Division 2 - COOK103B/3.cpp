# include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		char a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<int> indices, subs;
		for (int i = 1; i < n; i++) {
			if (a[i] == a[0]) indices.emplace_back(i);
		}
		int l = 1, mo = indices.size() - 1, ml = !indices.empty();
		while (!indices.empty()) {
			for (int i = indices.size() - 1; i >= 0; i--) {
				if (indices[i] <= l) {
					indices.erase(indices.begin() + i);
					continue;
				}
				if (a[indices[i] + l] != a[l]) {
					indices.erase(indices.begin() + i);
				}
			}
			l++;
			if (indices.size() > mo) {
				mo = indices.size() - 1;
				ml = l;
			}
		}
		if (ml == 0) {
			for (int i = 0; i < n; i++) {
				cout << a[i];
			}
		} else {
			for (int i = 0; i < ml; i++) {
				cout << a[i];
			}
		}
		cout << '\n';
	}
}
