#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n, k, b;
	vector<long long int> a;
	cin >> t;

	for (int i = 0; i < t; i++) {

		cin >> n >> k;
		a = *new vector<long long int>;
		for (int j = 0; j < n; j++) {
			cin >> b;
			a.push_back(b);
		}

		if (k == 2) {
			a.insert(a.end(), a.begin(), a.end());
		} else if (k > 2) {
			long long int ts = accumulate(a.begin(), a.end(), *new long long int(0));
			if (ts >= 0) {
				long long int cf = 0, mf = 0, cb = ts, mb = ts;
				for (long long l : a) {
					cf += l;
					cb -= l;
					if (cf > 0 && cf > mf) {
						mf = cf;
					}
					if (cb > 0 && cb > mb) {
						mb = cb;
					}
				}
				cout << (ts * (k - 2)) + mf + mb << '\n';
				continue;
			} else {
				a.insert(a.end(), a.begin(), a.end());
			}
		}

		long long int m = a[0];
		long long int c = a[0];

		for (long long l : a) {
			c = max(l, c + l);
			m = max(m, c);
		}
		m = max(m, *max_element(a.begin(), a.end()));
		cout << m << '\n';
	}
}
