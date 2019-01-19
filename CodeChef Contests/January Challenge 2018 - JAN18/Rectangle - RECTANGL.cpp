#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t, a, b, c, d;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c >> d;
		if (a == b && c == d) {
			cout << "YES\n";
		} else if (a == c && b == d) {
			cout << "YES\n";
		} else if (a == d && b == c) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
