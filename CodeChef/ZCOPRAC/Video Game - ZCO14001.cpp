// https://www.codechef.com/ZCOPRAC/problems/ZCO14001
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, H, c, p = 0;
	bool h = false;
	cin >> n >> H;
	long long a[n];
	for (long long i = 0; i < n; i++)
		cin >> a[i];

	while (true) {
		cin >> c;
		switch (c) {
			case 1:
				p = max(p - 1, 0ll);
				break;

			case 2:
				p = min(n - 1, p + 1);
				break;

			case 3:
				if ((a[p] > 0) and !h) {
					a[p]--;
					h = true;
				}
				break;

			case 4:
				if ((a[p] < H) and h) {
					a[p]++;
					h = false;
				}
				break;

			case 0:
				for (long long i = 0; i < n - 1; i++)
					cout << a[i] << " ";
				cout << a[n - 1];
				return 0;
		}
	}
}
