#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long t, p, idx, ans;
	cin >> t;

	while (t--) {
		cin >> p >> idx;
		ans = 0;

		for (int i = 0; i <= p; ++i) {
			if (idx & (1 << i)) {
				ans |= 1 << (p - i - 1);
			}
		}
		cout << ans << '\n';
	}
}
