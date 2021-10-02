#include <bits/stdc++.h>
using namespace std;

long long pow(long long a) {
	long long x = 1, y = a, b = 2711;
	while (b > 0) {
		if (b % 2 == 1) {
			x *= y;
			if (x > 2713) x %= 2713;
		}
		y *= y;
		if (y > 2713) y %= 2713;
		b /= 2;
	}
	return x;
}

long long C(long long n, long long r) {
	vector<long long> f(n, 1);
	for (int i = 2; i <= n; i++)
		f[i]= (f[i - 1] * i) % 2713;
	return (f[n]*((pow(f[r]) * pow(f[n-r])) % 2713)) % 2713;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n;
	long long m, nc2, a;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		nc2 = (n * (n - 1)) / 2;
		cout << C(nc2, m) << '\n';
	}
}
