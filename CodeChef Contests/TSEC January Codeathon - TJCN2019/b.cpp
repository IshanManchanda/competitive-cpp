#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	bool prime[1094602];

	memset(prime, true, sizeof(prime));
	for (int p = 2; p * p <= 1094601; p++) {
		if (prime[p]) {
			for (int i = p * p; i <= 1094601; i += p)
				prime[i] = false;
		}
	}

	int t, f1, f2, temp, c;
	cin >> t;
	while (t--) {
		cin >> f1 >> f2;
		c = prime[f1] + prime[f2];
		for (int i = 0; i < 18; i++) {
			temp = f2;
			f2 += f1;
			f1 = temp;
			c += prime[f2];
		}
		cout << c << '\n';
	}
}
