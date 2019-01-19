#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, r, a;
	cin >> n >> r;
	for (long long i = 0; i < n; i++) {
		cin >> a;
		if (a >= r) {
			cout << "Good boi" << endl;
		}
		else {
			cout << "Bad boi" << endl;
		}
	}
}
