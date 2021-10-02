#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, a, m = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		m += a % k == 0;
	}
	cout << m << "\n";
	return 0;
}
