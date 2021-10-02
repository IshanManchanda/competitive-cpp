#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n, k, x, y;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		bool r[n], c[n];
		vector<int> ans;

		for (int i = 0; i < n; i++) {
			r[i] = false;
			c[i] = false;
		}
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			r[x - 1] = true;
			c[y - 1] = true;
		}

		x = 0;
		y = 0;
		while (x < n && y < n) {

			while (r[x]) x++;
			while (c[y]) y++;
			if (x > n - 1 || y > n - 1) break;

			ans.push_back(x);
			ans.push_back(y);
			x++;
			y++;
		}

		cout << ans.size() / 2;
		for (int a : ans) cout << ' ' << a + 1;
		cout << '\n';
	}
}
