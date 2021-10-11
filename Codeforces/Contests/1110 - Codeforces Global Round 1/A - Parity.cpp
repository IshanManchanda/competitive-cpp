#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int b, k;
	cin >> b >> k;
	int digits[k];
	for (int i = 0; i < k; i++) cin >> digits[i];

	if (b % 2 == 0) {
		if (digits[k - 1] % 2 == 0) cout << "even";
		else cout << "odd";

	} else {
		int n = 0;
		for (int i = 0; i < k; i++) {
			n = (n + digits[i] % 2) % 2;
		}

		if (n == 0) cout << "even";
		else cout << "odd";
	}
}
