#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k, temp, prev;
	cin >> n >> m >> k;

	int a[n];
	cin >> prev;
	for (int i = 0; i < n - 1; i++) {
		cin >> temp;
		a[i] = temp - prev;
		prev = temp;

	}
	sort(a, a + n - 1);

	int ans = n;
	for (int i = 0; i < n - k; ++i)
		ans += a[i] - 1;

	cout << ans << endl;
	return 0;
}
