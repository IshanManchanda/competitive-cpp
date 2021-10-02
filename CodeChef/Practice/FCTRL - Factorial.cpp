#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, x, k, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		x = 0;
		m = 5;
		do {
			k = a / m;
			x += k;
			m *= 5;
		} while (k > 0);
		cout << x << '\n';
	}
	return 0;
}
