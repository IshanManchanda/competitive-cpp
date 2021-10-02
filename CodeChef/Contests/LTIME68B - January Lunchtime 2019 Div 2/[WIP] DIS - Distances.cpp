#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		long a[n], b[n], ma = 1000000001, mb = 1000000001, m, y = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		if (a[0] != 0 || b[n - 1] != 0) {
			cout << "No\n";
			continue;
		}
		for (int i = 1; i < n; i++) {
			ma = min(ma, a[i]);
			mb = min(mb, b[n - i - 1]);
		}
		m = ma + mb;

		for (int i = 0; i < n; i++) {
			if (max(a[i], b[i]) > (min(a[i], b[i]) + m)) {
				cout << "No\n";
				y = 0;
				break;
			}
		}
		if (y) {
			cout << "Yes\n";
		}
	}
}
