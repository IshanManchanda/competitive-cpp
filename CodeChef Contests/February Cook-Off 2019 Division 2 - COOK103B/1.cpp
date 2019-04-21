#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n, b, h, w, p;
	cin >> t;
	while (t--) {
		long long a = -1;
		cin >> n >> b;
		for (int i = 0; i < n; i++) {
			cin >> w >> h >> p;
			if (p > b) continue;
			a = max(a,(long long) w * h);
		}
		if (a == -1) cout << "no tablet\n";
		else cout << a << '\n';
	}
}
