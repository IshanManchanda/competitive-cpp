#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, l, d, h;
	cin >> t;
	while (t--) {
		cin >> l >> d >> h;
		if (l * h < d) {
			cout << "No\n";
		}
		else {
			cout << "Yes\n";
		}
	}

}
