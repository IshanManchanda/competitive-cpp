// https://www.codechef.com/ZCOPRAC/problems/ZCO14003
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, ans = 0;
	cin >> n;

	long long a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);

	for (int i = 0; i < n; ++i)
		ans = max(ans, a[i] * (n - i));
	cout << ans << '\n';
}
