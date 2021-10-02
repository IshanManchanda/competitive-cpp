#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(2);

	int a;
	float b;
	cin >> a >> b;
	if (a != 0) {
		if (a % 5 == 0) {
			if (b >= float(a) + 0.5) {
				b -= float(a) + 0.5;
			}
		}
	}
	cout << b << "\n";
	return 0;
}
