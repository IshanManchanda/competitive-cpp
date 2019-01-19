#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long k, n, m, x, y;

	while (true) {
		cin >> k;
		if (k == 0) {
			return 0;
		}
		cin >> n >> m;
		while (k--) {
			cin >> x >> y;
			if (x == n || y == m) {
				cout << "divisa" << endl;
			}
			else if (x > n) {
				if (y > m) {
					cout << "NE" << endl;
				}
				else {
					cout << "SE" << endl;
				}
			}
			else {
				if (y > m) {
					cout << "NO" << endl;
				}
				else {
					cout << "SO" << endl;
				}
			}
		}
	}


}
