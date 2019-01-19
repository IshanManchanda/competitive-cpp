#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unsigned int t, n;
	long long int temp, last, b;
	cin >> t;

	for (int i = 0; i < t; i++){
		cin >> n;
		vector<vector<long long int>> a(n, vector<long long int>(n));
		b = 0;

		for (unsigned int j = 0; j < n; j++) {
			for (unsigned int k = 0; k < n; k++) {
				cin >> temp;
				a[j][k] = temp;
			}
		}
		last = INFINITY;
		for (int j = n - 1; j > -1; j--) {
			temp = -1;
			for (unsigned int k = 0; k < n; k++) {
				if (a[j][k] > temp && a[j][k] < last) {
					temp = a[j][k];
				}
			}
			if (temp == -1) {
				cout << -1 << '\n';
				goto c;
			}
			last = temp;
			b += last;
		}
		cout << b << '\n';
		c:
		continue;
	}
}
