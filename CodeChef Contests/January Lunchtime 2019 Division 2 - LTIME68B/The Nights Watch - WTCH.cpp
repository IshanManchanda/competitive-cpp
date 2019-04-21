#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n, c;
	cin >> t;
	while (t--) {
		cin >> n;
		char arr[n];
		c = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if (n == 1) {
			cout << ((arr[0] == '0') ? 1 : 0) << '\n';
			continue;
		}

		if (arr[0] == '0' && arr[1] == '0') {
			arr[0] = '1';
			c++;
		}
		if (arr[n - 1] == '0' && arr[n - 2] == '0') {
			arr[n - 1] = '1';
			c++;
		}
		for (int i = 2; i < n - 2; i++) {
			if (arr[i] == '1' || arr[i - 1] == '1' || arr[i + 1] == '1') {
				continue;
			}
			arr[i] = '1';
			c++;
		}
		cout << c << '\n';
	}

}
