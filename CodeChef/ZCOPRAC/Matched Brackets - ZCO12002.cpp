#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, a, d = 0, md = 0, mdp = 0, s = 0, ms = 0, sp = 0, msp = 0;
	cin >> n;
	for (long long i = 0; i < n; i ++) {
		cin >> a;
		if (a == 1) {
			if (d == 0) {
				sp = i;
			}
			else {
				s++;
			}
			d++;
			if (d > md) {
				md = d;
				mdp = i;
			}
		}
		else {
			d--;
			s++;
			if (d == 0) {
				if (s > ms) {
					ms = s;
					msp = sp;
				}
				s = 0;
			}
		}
	}

	cout << md << ' ';
	cout << mdp + 1 << ' ';
	cout << ms + 1 << ' ';
	cout << msp + 1 << ' ';
}
